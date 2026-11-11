#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IL inline
const int N = 505, M = 5e5 + 5;
const ll INF = 1e17;
ll w[M], f[N][N];
vector<int> line[M], id[M];
int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int cid, n, m, d, q;
  cin >> cid >> m >> n >> d >> q;
  for (int i = 1; i <= n; ++i)
    cin >> w[i];
  vector<vector<int>> nodes(m);
  vector<vector<int>> t(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    nodes[i].resize(k);
    t[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> nodes[i][j] >> t[i][j];
      line[nodes[i][j]].push_back(i);
      id[nodes[i][j]].push_back(j);
    }
  }
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < m; ++j)
      f[i][j] = INF;
  for (int i = 0; i < m; ++i)
    f[i][i] = 0;
  for (int u = 1; u <= n; ++u) {
    int tot = line[u].size();
    for (int i = 0; i < tot; ++i) {
      for (int j = i + 1; j < tot; ++j) {
        int x = line[u][i], y = line[u][j];
        ll tim = t[x][id[u][i]] + t[y][id[u][j]];
        f[x][y] = min(f[x][y], tim);
        f[y][x] = min(f[y][x], tim);
      }
    }
  }
  for (int k = 0; k < m; ++k)
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < m; ++j)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  while (q--) {
    int u, v;
    cin >> u >> v;
    ll ans = INF;
    int totu = line[u].size();
    int totv = line[v].size();
    for (int i = 0; i < totu; ++i) {
      for (int j = 0; j < totv; ++j) {
        int fr = line[u][i], to = line[v][j];
        ll tim = t[fr][id[u][i]] + t[to][id[v][j]];
        ans = min(ans, f[fr][to] + tim);
      }
    }
    cout << ans + w[u] + w[v] << '\n';
  }
  return 0;
}