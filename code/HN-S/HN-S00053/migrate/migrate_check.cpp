#include <bits/stdc++.h>

using namespace std;
using LL = long long;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

const int kMaxN = 2e6 + 1;

LL a[kMaxN], f[kMaxN], g[kMaxN], tc, t, n, d, ans;

int main() {
  for (fin >> tc >> t; t--;) {
    fin >> n >> d;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      fin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      fill(f + 1, f + 1 + n, 1e9);
      fill(g + 1, g + 1 + n, 0);
      f[i] = 0, g[i] = 1;
      for (int j = i + 1; j <= n; j++) {
        for (int k = i; k < j; k++) {
          if (a[j] - a[k] <= d) {
            if (f[k] + 1 < f[j]) {
              f[j] = f[k] + 1;
              g[j] = g[k];
            } else if (f[k] + 1 == f[j]) {
              g[j] += g[k];
            }
          }
        }
        if (i == 1) {
          cerr << j << ' ' << f[j] << ' ' << g[j] << '\n';
        }
        ans += g[j] == 2;
        if (g[j] == 2) {
          cerr << i << ' ' << j << '\n';
        }
      }
    }
    fout << ans;
  }
  return 0;    
}