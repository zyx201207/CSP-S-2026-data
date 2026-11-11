#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 5e2 + 5, M = 5e5 + 10;
int n, m, q;
ll wu[M], dis[N][N];
std::vector<std::pair<int, ll>> rt[M];
int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  scanf("%*d%d%d%*d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) scanf("%lld", &wu[i]);
  for (int i = 1; i <= n; i++) {
    int k; scanf("%d", &k);
    for (int u, w; k--; ) {
      scanf("%d%d", &u, &w);
      rt[u].emplace_back(i, w);
    }
  }
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; i++)
    dis[i][i] = 0;
  for (int i = 1; i <= m; i++) {
    for (auto [x1, y1] : rt[i])
      for (auto [x2, y2] : rt[i])
        dis[x1][x2] = std::min(dis[x1][x2], y1 + y2);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int u, v; q--; ) {
    scanf("%d%d", &u, &v);
    ll ans = 1e18;
    for (auto [xu, yu] : rt[u])
      for (auto [xv, yv] : rt[v])
        ans = std::min(ans, yu + dis[xu][xv] + yv);
    printf("%lld\n", ans + wu[u] + wu[v]);
  }
  return 0;
}