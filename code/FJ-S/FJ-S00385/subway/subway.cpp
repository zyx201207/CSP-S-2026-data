#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

using ll = long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using node = pair<ll, pii>;

int c, n, m, d, q;
int w[500005], k[505];
vector<vector<node>> E[505];
vector<ll> dis[505];
vector<bool> vis[505];

void dijkstra(ll s) {
  for (int i = 0; i <= n; i++) {
    fill(dis[i].begin(), dis[i].end(), 0x3f3f3f3f3f3f3f3f);
    fill(vis[i].begin(), vis[i].end(), 0);
  }
  priority_queue<node, vector<node>, greater<>> q;
  q.emplace(0, pii{0, s});
  dis[0][s] = 0;
  while (q.size()) {
    auto u = q.top().second;
    q.pop();
    if (vis[u.first][u.second])
      continue;
    vis[u.first][u.second] = 1;
    for (auto i : E[u.first][u.second]) {
      ll w = i.first;
      auto v = i.second;
      if (dis[v.first][v.second] > dis[u.first][u.second] + w) {
        dis[v.first][v.second] = dis[u.first][u.second] + w;
        q.emplace(dis[v.first][v.second], v);
      }
    }
  }
}

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++)
    cin >> w[i];
  E[0].resize(m + 1);
  dis[0].resize(m + 1);
  vis[0].resize(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    E[i].resize(k[i] + 1);
    dis[i].resize(k[i] + 1);
    vis[i].resize(k[i] + 1);
    for (int j = 1; j <= k[i]; j++) {
      int a, t;
      cin >> a >> t;
      E[i][j].emplace_back(t, pii{0, a});
      E[0][a].emplace_back(t, pii{i, j});
      if (j > 1) {
        E[i][j].emplace_back(0, pii{i, j - 1});
        E[i][j - 1].emplace_back(0, pii{i, j});
      }
    }
}
  while (q--) {
    int s, t;
    cin >> s >> t;
    dijkstra(s);
    cout << dis[0][t] + w[s] + w[t] << '\n';
  }
  return 0;
}


