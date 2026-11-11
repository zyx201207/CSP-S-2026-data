#include <bits/stdc++.h>

namespace ZeroOf149 {

using std::cin;
using std::cout;

constexpr int N = 1e6 + 5, Inf = 0x3f3f3f3f;

struct MX2 {
  MX2() = default;
  MX2(int p, int q, int r) : m1{p}, m2{q}, m3{r} {}
  
  void update(int x) {
    if (x >= m1)
      m3 = m2, m2 = m1, m1 = x;
    else if (x >= m2)
      m3 = m2, m2 = x;
    else if (x >= m3)
      m3 = x;
  }
  
  void cancel(int v) {
    if (v == m1)
      m1 = m2, m2 = m3;
    else if (v == m2)
      m2 = m3;
  }
  
  int m1, m2, m3;
};

int c, TT, n, k, dis, fa[N], dp1[N], dpr[N], dp2[N], dm1[N];
// 1 subtree
// 2 anti subtree
// r root
MX2 h[N], h2[N];
std::vector<int> g[N];

void init(int u, int f) {
  fa[u] = f;
  for (auto&& v : g[u]) {
    if (v == f) continue;
    init(v, u);
  }
}

int solve(int u, int f, int* src, int nd = 0) {
  int mn = Inf;
  if (nd <= dis)
    mn = src[u];
  else
    return Inf;
  auto oh = h[u];
  for (auto&& v : g[u]) {
    if (v == f) continue;
    h[u].cancel(h[v].m1 + 1);
    mn = std::min(mn, solve(v, u, src, std::max(nd, h[u].m1) + 1));
    h[u] = oh;
  }
  return mn;
}

void dfs1(int u, int f) {
  dp1[u] = 1;
  for (auto&& v : g[u]) {
    if (v == f) continue;
    dfs1(v, u);
    h[u].update(h[v].m1 + 1);
    if (h[v].m1 + 1 > dis) dp1[u] += dp1[v];
  }
  dm1[u] = solve(u, f, dp1);
}

bool dfs2(int u, int f) {
  if (f) {
    h[u].update(h[f].m1 + 1);
    if (h[f].m1 + 1 > dis) dpr[u] += dpr[f];
    if (solve(f, u, dp2) + dm1[u] <= k) return true;
  }
  auto oh = h[u];
  auto oh2 = h2[u];
  auto odp = dpr[u];
  for (auto&& v : g[u]) {
    if (v == f) continue;
    if (h[v].m1 + 1 > dis) dpr[u] -= dpr[v];
    h[u].cancel(h[v].m1 + 1);
    dp2[u] = dpr[u];
    h2[u] = h[u];
    if (dfs2(v, u)) return true;
    h2[u] = oh2;
    dp2[u] = dp1[u];
    h[u] = oh;
    dpr[u] = odp;
  }
  return false;
}

bool check(int mid) {
  dis = mid;
  std::fill(dp1 + 1, dp1 + n + 1, 1);
  std::fill(h + 1, h + n + 1, MX2{0, 0, 0});
  dfs1(1, 0);
  if (dm1[1] <= k) return true;
  std::copy(dp1 + 1, dp1 + n + 1, dp2 + 1);
  std::copy(h + 1, h + n + 1, h2 + 1);
  std::copy(dp1 + 1, dp1 + n + 1, dpr + 1);
  return dfs2(1, 0);
}

int my_main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  
  for (cin >> c >> TT; TT--; ) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (k == n) {
      cout << "0\n";
      continue;
    }
    init(1, 0);
    int l = 0, r = n - 1;
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      (check(mid) ? r : l) = mid;
    }
    cout << r << '\n';
  }
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }

