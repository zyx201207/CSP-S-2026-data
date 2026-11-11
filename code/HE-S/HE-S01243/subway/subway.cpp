#include <bits/stdc++.h>
#define up(i,l,r) for (int i = l, E##i = r; i <= E##i; ++i)
using namespace std;
using L = long long;
constexpr L M = 5e5 + 5, N = 505, Q = 1e5 + 5;
L c, n, m, D, q, k[N], w[M], x[Q], y[Q];
vector<pair<int, int>> sr[M], rs[N];
L d[N][N];
void solve1() {
  memset(d, 0x3f, sizeof d);
  up (i, 1, n) d[i][i] = 0;
  up (i, 1, m) {
    for (auto p1 : sr[i]) {
      L i1 = p1.first, t1 = p1.second;
      for (auto p2 : sr[i]) {
        L i2 = p2.first, t2 = p2.second;
        d[i1][i2] = d[i2][i1] = min(d[i1][i2], t1 + t2);
      }
    }
  }
  up (k, 1, n) up(i, 1, n) up(j, 1, n)
  d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
  up (i, 1, q) {
    L ans = LLONG_MAX;
    for (auto p1 : sr[x[i]]) {
      L i1 = p1.first, t1 = p1.second;
      for (auto p2 : sr[y[i]]) {
        L i2 = p2.first, t2 = p2.second;
        ans = min(ans, t1 + t2 + d[i1][i2]);
      }
    }
    cout << ans + w[x[i]] + w[y[i]] << '\n';
  }
}
int main () {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> c >> n >> m >> D >> q;
  up (i, 1, m) cin >> w[i];
  up (i, 1, n) {
    L a, t;
    cin >> k[i];
    up (j, 1, k[i]) {
      cin >> a >> t;
      sr[a].push_back({i, t});
      rs[i].push_back({a, t});
    }
  }
  up (i, 1, q) cin >> x[i] >> y[i];
  solve1();
  return 0;
}
