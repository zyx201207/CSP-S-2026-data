#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;
int c, n, m, d, q, w[N];
ll dis[505][505];
vector<pair<int, int>> f[N];
int main() {
   freopen("subway.in", "r", stdin);
   freopen("subway.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> c >> n >> m >> d >> q;
   for (int i = 1; i <= m; i++) cin >> w[i];
   for (int i = 1, k; i <= n; i++) {
      cin >> k;
      for (int j = 1, x, t; j <= k; j++) cin >> x >> t, f[x].push_back({i, t});
   }
   for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
         dis[i][j] = dis[j][i] = 1e18;
   for (int i = 1; i <= m; i++)
      for (auto [x, t1] : f[i])
         for (auto [y, t2] : f[i])
            dis[x][y] = min(dis[x][y], (ll)(t1 + t2));
   for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
   for (int i = 1, x, y; i <= q; i++) {
      cin >> x >> y;
      ll res = 1e18;
      for (auto [u, t1] : f[x])
         for (auto [v, t2] : f[y])
            res = min(res, dis[u][v] + t1 + t2);
      cout << res + w[x] + w[y] << "\n";
   }
   return 0;
}