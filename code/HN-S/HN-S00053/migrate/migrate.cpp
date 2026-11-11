#include <bits/stdc++.h>

using namespace std;
using LL = long long;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

const int kMaxN = 2e6 + 1;

LL a[kMaxN], pr[kMaxN], ne[kMaxN], f[kMaxN], g[kMaxN], sg[kMaxN], h[kMaxN], tc, t, n, d;

void SB() {
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
      f[i] = 1, g[i] = h[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      if (ne[i] == i + 1) {
        f[i + 1] += f[i];
      }
    }
    for (int i = 1; i < n; i++) {
      if (ne[i] > i + 1) {
        g[ne[i] - 1] += f[i];
      }
    }
    for (int i = 1; i < n; i++) {
      if (ne[i] > i + 1 && ne[i + 1] == ne[i] + 1) {
        g[ne[i]] += g[i];
      }
    }
    for (int i = 2; i <= n; i++) {
      if (pr[i] == i - 1) {
        h[i] = h[pr[i]];
      } else if (pr[i] < i - 1) {
        h[i] = g[pr[i]];
      }
      ans += h[i];
    }
    fout << ans << '\n';
}

int main() {
  for (fin >> tc >> t; t--;) {
    fin >> n >> d;
    for (int i = 1, j = 1; i <= n; i++) {
      fin >> a[i];
      for (; a[i] - a[j] > d; j++) {
      }
      pr[i] = j;
    }
    for (int i = n, j = n; i >= 1; i--) {
      for (; a[j] - a[i] > d; j--) {
      }
      ne[i] = j;
    }
    if (tc > 10) {
      SB();
    } else {
      LL ans = 0;
      for (int i = 1; i <= n; i++) {
        sg[i - 1] = f[i] = 0, g[i] = sg[i] = 1;
        for (int j = i + 1, k = i; j <= n && pr[j] != j; j++) {
          int x = max(pr[j], 0LL + i);
          f[j] = f[x] + 1;
          for (; f[k] <= f[x]; k++) {
          }
          g[j] = sg[k - 1] - sg[x - 1];
          sg[j] = sg[j - 1] + g[j];
          ans += g[j] == 2;
        }
      }
      fout << ans << '\n';
    }
  }
  return 0;    
}