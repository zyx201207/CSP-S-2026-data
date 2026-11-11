#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e6 + 5, NN = 5e3 + 5;

LL c, t, n, a[N], p[N], ans, dd;
int d[NN][NN], f[NN][NN];

int main () {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> c;
  if (c <= 10) {
    for (cin >> t; t--;) {
      cin >> n >> dd;
      fill(&d[0][0], &d[n + 1][0], n + 1);
      for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i][i] = 0;
      }
      ans = 0;
      fill(&f[0][0], &f[n + 1][0], 0);
      for (int i = 2; i <= n; i++) {
        p[i] = lower_bound(a + 1, a + i, a[i] - dd) - a;
        if (p[i] < i) {
          for (int j = 1; j <= p[i]; j++) {
            d[j][i] = d[j][p[i]] + 1;
          }
          for (int j = p[i] + 1; j < i; j++) {
            d[j][i] = 1;
          }
        }
      }
      for (int i = 2; i <= n; i++) {
        if (p[i] >= i) continue;
        for (int j = 1; j <= p[i]; j++) {
          f[i][j] = f[p[i]][j];
        }
        if (p[i] + 1 < i) {
          for (int j = 1; j <= p[i] + 1; j++) {
            if (d[j][p[i]] == d[j][p[i] + 1] && d[j][p[i]] <= n) {
              if (!f[p[i]][j] && !f[p[i] + 1][j]) {
                f[i][j] = 1;
              } else {
                f[i][j] = 2;
              }
            }
          }
        }
        if (p[i] + 2 < i) {
          for (int j = 1; j <= p[i] + 2; j++) {
            if (d[j][p[i]] == d[j][p[i] + 2] && d[j][p[i]] <= n) {
              f[i][j] = 2;
            }
          }
        }
        for (int j = 1; j <= i; j++) {
          ans += f[i][j] == 1;
        }
      }
      cout << ans << '\n';
    }
    return 0;
  }
  return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
//退！役！