#ifndef BLOBBY3D_MYCONDITIONALPRIOR_H_
#define BLOBBY3D_MYCONDITIONALPRIOR_H_

#include "DNest4/code/DNest4.h"

// Hyperparameters setting interim prior for galaxy properties
class MyConditionalPrior:public DNest4::ConditionalPrior {
 private:
  // Limits
  double x_min, x_max, y_min, y_max;
  double r_min, r_max; 
  double dx, dy, dr;
  double x_pad_dx, y_pad_dy;
  double fluxlim_min, fluxlim_max; 
  double radiuslim_min, radiuslim_max;

  // Exponential for wd
  double wd_min, wd_width;
  double wd;

  // Lognormal for flux
  double flux_mu;
  double fluxlim_width;
  double flux_var, flux_std;
  double flux_std_min, flux_std_width;

  double n2flux_mu;
  double n2fluxlim_width;
  double n2flux_var, n2flux_std;
  double n2flux_std_min, n2flux_std_width;

  // Loguniform with changing limits for W
  double radiuslim_width;
  double radiusmin, radiusmax;

  // Triangular with changing lower limit
  double qlim_min;
  double q_min;

  double perturb_hyperparameters(DNest4::RNG& rng);

 public:
   MyConditionalPrior(
     double x_min, double x_max,
     double y_min, double y_max,
     double r_min, double r_max, 
     double dx, double dy, double dr,
     double x_pad_dx, double y_pad_dy,
     double fluxlim_min, double fluxlim_max
     );

   void from_prior(DNest4::RNG& rng);

   double log_pdf(const std::vector<double>& vec) const;
   void from_uniform(std::vector<double>& vec) const;
   void to_uniform(std::vector<double>& vec) const;

   void print(std::ostream& out) const;
};

#endif  // BLOBBY3D_MYCONDITIONALPRIOR_H_

