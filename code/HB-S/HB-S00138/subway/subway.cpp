#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
const int N = 505, M = 5e5 + 5;
int testid, n, m, d, qwq, w[M];
namespace task7_8 {
  ll dis[1005][1005];
  bool vis[1005];
  vector<pii> e[1005];
  priority_queue<pli, vector<pli>, greater<pli>> q;
  void dijkstra(int s) {
    memset(vis, 0, sizeof(vis));
    dis[s][s] = 0; q.push({0, s});
    while (!q.empty()) {
      int u = q.top().se; q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (pii i : e[u]) {
        int v = i.fi, w = i.se;
        if (dis[s][v] > dis[s][u] + w) {
          dis[s][v] = dis[s][u] + w; q.push({dis[s][v], v});
        }
      }
    }
  }
  void main() {
    for (int i = 1; i <= n; i ++) {
      int k, a1, t1, a2, t2;
      cin >> k >> a1 >> t1;
      if (k == 1) continue;
      cin >> a2 >> t2;
      e[a1].push_back({a2, t1 + t2});
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i ++) dijkstra(i);
    while (qwq --) {
      int u, v; cin >> u >> v;
      cout << dis[u][v] + w[u] + w[v] << "\n";
    }
    exit(0);
  }
}
// namespace taskB { // wei shen me hui he brute chong tu a?
//   int k[N], a[N][M], dis[M], T;
//   bool book[N][M];
//   queue<int> q;
//   int bfs(int s, int t) {
//     memset(dis, -1, sizeof(dis));
//     while (!q.empty()) q.pop();
//     dis[s] = 0; q.push(s);
//     while (!q.empty()) {
//       int u = q.front(); q.pop();
//       for (int i = 1; i <= n; i ++) if (book[i][u])
//         for (int j = 1; j <= k[i]; j ++) {
//           if (a[i][j] == u) continue;
//           if (dis[a[i][j]] == -1) {
//             dis[a[i][j]] = dis[u] + 1; q.push(u);
//           }
//         }
//     }
//     return dis[t];
//   }
//   void main() {
//     for (int i = 1; i <= n; i ++) {
//       cin >> k[i];
//       for (int j = 1; j <= k[i]; j ++) {
//         cin >> a[i][j] >> T; book[i][a[i][j]] = true;
//       }
//     }
//     while (qwq --) {
//       int u, v; cin >> u >> v;
//       cout << (ll)bfs(u, v) * 2 * T + w[u] + w[v] << "\n";
//     }
//     exit(0);
//   }
// }
namespace brute {
  int t[M][N];
  ll ans;
  vector<pii> e[M];
  void dfs(int u, int to, int pre, ll d) {
    if (u == to) { ans = min(ans, d + t[u][pre]); return; }
    for (pii i : e[u]) {
      int v = i.fi, id = i.se;
      if (pre != id) dfs(v, to, id, d + t[u][pre] + t[u][id]);
      else dfs(v, to, id, d);
    }
  }
  void main() {
    for (int i = 1; i <= n; i ++) {
      int k, lst = 0; cin >> k;
      while (k --) {
        int a; cin >> a >> t[a][i];
        if (lst) e[lst].push_back({a, i});
        lst = a;
      }
    }
    while (qwq --) {
      int u, v; cin >> u >> v;
      ans = 1e18; dfs(u, v, 0, 0);
      cout << ans + w[u] + w[v] << "\n";
    }
    exit(0);
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> testid >> n >> m >> d >> qwq;
  for (int i = 1; i <= m; i ++) cin >> w[i];
  if (7 <= testid && testid <= 8) task7_8::main();
  // else if (12 <= testid && testid <= 19) taskB::main();
  else brute::main();
  return 0;
}