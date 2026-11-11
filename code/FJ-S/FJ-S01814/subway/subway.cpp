#include <bits/stdc++.h>
#define eb emplace_back
#define sz(x) int((x).size())

using LL = long long;
using namespace std;

const int N = 510, M = 5e5 + 10;
int w[M];
LL g[N][N];
vector<pair<int, int>> G[M];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int c, n, m, d, q;
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  memset(g, 0x3f, sizeof g);
  for (int i = 1; i <= n; i++) g[i][i] = 0;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    vector<int> a(k), t(k);
    for (int j = 0; j < k; j++) {
      cin >> a[j] >> t[j];
      G[a[j]].eb(i, t[j]);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < sz(G[i]); j++) {
      for (int k = j + 1; k < sz(G[i]); k++) {
        auto [u, x] = G[i][j];
        auto [v, y] = G[i][k];
        g[u][v] = g[v][u] = min(g[u][v], LL(x + y));
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    LL ans = 1e18;
    for (int i = 0; i < sz(G[u]); i++) {
      for (int j = 0; j < sz(G[v]); j++) {
        auto [a, x] = G[u][i];
        auto [b, y] = G[v][j];
        ans = min(ans, x + y + g[a][b]);
      }
    }
    cout << ans + w[u] + w[v] << '\n';
  }
  return 0;
}