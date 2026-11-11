#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 555, N = 5e5 + 5;

struct NODE {
  int v, w;
};

int cy, n, m, d, q, puck[N], tot[N], t;
vector<NODE> g[N + N * 20 + M];             // i(1 <= i <= n) 表示 i 号站厅，i + kn 表示 i 地铁站的第 k 条路线的站台，dn + x 表示第 x 条路线的虚拟点 x

namespace subtask1 {
  bool check() {
    return cy <= 8;
  }

  struct Node {
    int u;
    ll d;

    bool operator < (const Node &i) const {
      return d > i.d;
    }
  };

  const ll INF = 1e18;

  ll dist[N + N * 20 + M];

  void Dijkstra(int s, ll x) {
    priority_queue<Node> pq;
    fill(dist, dist + n + n * 20 + m, INF);
    pq.push({s, x});
    dist[s] = x;
    while (!pq.empty()) {
      ll u = pq.top().u, d = pq.top().d;
      pq.pop();
      if (dist[u] != d) continue ;
      for (NODE i : g[u]) {
        int v = i.v, w = i.w;
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.push({v, dist[v]});
        }
      }
    }
  }

  void solve() {
    while (q--) {
      int x, y;
      cin >> x >> y;
      Dijkstra(x, puck[x]);
      cout << dist[y] + puck[y] << "\n";
    }
  }
} // 32pts

namespace subtask2 {
  bool check() {
    return cy <= 15 && cy >= 12;
  }

  const ll INF = 1e18;

  struct Node {
    int u, d;
  };

  ll dist[N + N * 20 + M];

  void bfs(int s) {
    fill(dist, dist + n + 20 * n + m, INF);
    deque<Node> q;
    q.push_back({s, 0});
    dist[s] = 0;
    while (!q.empty()) {
      int u = q.front().u;
      ll d = q.front().d;
      q.pop_front();
      if (dist[u] != d) continue ;
      for (NODE i : g[u]) {
        if (dist[i.v] > dist[u] + (i.w == 0 ? 0 : 1)) {
          dist[i.v] = dist[u] + (i.w == 0 ? 0 : 1);
          if (i.w == 0) {
            q.push_front({i.v, dist[i.v]});
          } else {
            q.push_back({i.v, dist[i.v]});
          }
        }
      }
    }
  }

  void solve() {
    while (q--) {
      int x, y;
      cin >> x >> y;
      bfs(x);
      cout << puck[x] + puck[y] + dist[y] * t << "\n";
    }
  }
}

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> cy >> m >> n >> d >> q;
  for (int i = 1; i <= n; i++) {
    cin >> puck[i];
  }
  for (int i = 1, k; i <= m; i++) {
    cin >> k;
    for (int j = 1, x, y; j <= k; j++) {
      cin >> x >> y;
      tot[x]++;
      t = y;
      g[tot[x] * n + x].push_back({i + d * n, 0}), g[i + d * n].push_back({tot[x] * n + x, 0});
      g[tot[x] * n + x].push_back({x, y}), g[x].push_back({tot[x] * n + x, y});
    }
  }
  if (subtask2::check()) {
    subtask2::solve();
  } else {
    subtask1::solve();
  }
  return 0;
}
