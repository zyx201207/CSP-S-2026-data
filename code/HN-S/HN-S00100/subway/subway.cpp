#include <bits/stdc++.h>
#define LL long long

using namespace std;

const LL N = 505, M = 5e5 + 5, inf = 1e18;

LL c, n, m, d, q, f[N][N], w[M];
struct node {
  LL i, zs;
};
vector <node> v[M];

int main () {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int j = 1, x, vv; j <= k; j++) {
      cin >> x >> vv;
      v[x].emplace_back((node){i, vv});
    }
  }
  fill(&f[0][0], &f[n + 1][0], inf);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      for (int k = j + 1; k < v[i].size(); k++) {
        int x = v[i][j].i, y = v[i][k].i;
        f[x][y] = min(f[x][y], v[i][j].zs + v[i][k].zs);
        f[y][x] = min(f[y][x], v[i][j].zs + v[i][k].zs);
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    f[k][k] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  for (int x, y; q--;) {
    cin >> x >> y;
    LL ans = inf;
    for (node i : v[x]) {
      for (node j : v[y]) {
        ans = min(ans, w[x] + w[y] + i.zs + j.zs + f[i.i][j.i]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}