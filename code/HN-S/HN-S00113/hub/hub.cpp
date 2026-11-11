#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 6;

int cy, t, n, k, vis[N], vv[N], dist[N], ans;
vector<int> g[N];

struct Node {
  int u, d;
};

const int INF = 1e9;

void bfs() {
  queue<Node> q;
  fill(dist + 1, dist + n + 1, INF);
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      q.push({i, 0});
      dist[i] = 0;
    }
  }
  while (!q.empty()) {
    int u = q.front().u, d = q.front().d;
    q.pop();
    if (dist[u] != d) continue ;
    for (int v : g[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push({v, dist[u] + 1});
      }
    }
  }
}

void dfs1(int x) {
  vv[x] = 1;
  for (int v : g[x]) {
    if (vis[v] && !vv[v]) {
      dfs1(v);
    }
  }
}

void dfs(int x) {
  if (x == n + 1) {
    int cnt = 0, ccnt = 0;
    fill(vv + 1, vv + n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (vis[i] && !vv[i]) {
        dfs1(i);
        cnt++;
      }
      ccnt += vis[i];
    }
    if (cnt > 2 || ccnt != k) return ;
    bfs();
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      mx = max(mx, dist[i]);
    }
    ans = min(ans, mx);
    return ;
  }
  vis[x] = 1;
  dfs(x + 1);
  vis[x] = 0;
  dfs(x + 1);
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  ans = INF;
  dfs(1);
  cout << ans << "\n";
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> cy >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// 12pts
