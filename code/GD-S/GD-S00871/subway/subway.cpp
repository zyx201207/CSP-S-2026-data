#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 510;
constexpr int M = 5e5 + 10;
constexpr i64 inf = 1e18;

int w[M];

vector<pair<int, int>> line[M];

i64 dis[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);

  int c, n, m, d, q;
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int x, y;
      cin >> x >> y;
      line[x].emplace_back(i, y);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        dis[i][j] = inf;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    int len = line[i].size();
    for (int j = 0; j < len - 1; j++) {
      for (int k = j + 1; k < len; k++) {
        int u = line[i][j].first;
        int v = line[i][k].first;
        i64 wt = line[i][j].second + line[i][k].second;
        dis[u][v] = dis[v][u] = min(dis[u][v], wt);
      }
    }
  }

  

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << i << ' ' << j << ' ' << dis[i][j] << endl;
  //   }
  // }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    i64 res = inf;
    for (auto& [u, w1] : line[x]) {
      for (auto [v, w2] : line[y]) {
        res = min(res, dis[u][v] + w1 + w2);
      }
    }
    cout << res + w[x] + w[y] << '\n';
  }

  return 0;
}