#include <bits/stdc++.h>

namespace ZeroOf149 {

using std::cin;
using std::cout;

using ll = long long;

constexpr int N = 5e2 + 5, M = 5e5 + 5;
constexpr ll Inf = 0x3f3f3f3f3f3f3f3f;

struct Ec {
  Ec(int v_, int w_) : v{v_}, w{w_} {}
  
  int v, w;
};

int c, n, m, d, T, w[M];
ll g[N][N];
std::vector<Ec> od[M];

inline void cmin(ll& x, ll y) { x = std::min(x, y); }

int my_main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> c >> n >> m >> d >> T;
  for (int i = 1; i <= m; ++i) cin >> w[i];
  for (int u = 1, k; u <= n; ++u) {
    cin >> k;
    for (int j = 1, v, w; j <= k; ++j) {
      cin >> v >> w;
      od[v].emplace_back(u, w);
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) g[i][j] = (i == j ? 0 : Inf);
  for (int i = 1, s; i <= m; ++i) {
    s = (int)od[i].size();
    for (int j = 0; j < s; ++j)
      for (int k = 0; k < j; ++k) {
        auto u = od[i][j].v, v = od[i][k].v, w = od[i][j].w + od[i][k].w;
        cmin(g[u][v], w);
        cmin(g[v][u], w);
      }
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) cmin(g[i][j], g[i][k] + g[k][j]);
  for (int t = 1, u, v; t <= T; ++t) {
    cin >> u >> v;
    ll Ans = Inf;
    for (auto&& p : od[u])
      for (auto&& q : od[v]) cmin(Ans, p.w + g[p.v][q.v] + q.w);
    cout << w[u] + Ans + w[v] << '\n';
  }
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }

