#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  int c, n, m, d, q;
  cin >> c >> n >> m >> d >> q;
  vector<i64> w(m + 1);
  vector<vector<i64>> a(n + 1);
  vector<vector<i64>> t(n + 1);
  for (int i = 1; i <= m; i++) cin >> w[i];
  vector<vector<pair<int, int>>> graph(m + 1);
  vector<vector<int>> lines(m + 1);
  map<pair<int, int>, long long> time;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    a[i].resize(k + 1); 
    t[i].resize(k + 1);
    for (int j = 1; j <= k; j++) cin >> a[i][j] >> t[i][j], lines[a[i][j]].push_back(i);
    for (int j = 2; j <= k; j++) {
      graph[a[i][j - 1]].push_back({a[i][j], i});
      graph[a[i][j]].push_back({a[i][j - 1], i});
      time[{a[i][j], i}] = t[i][j];
//      cout << a[i][j - 1] << " connects to " << a[i][j] << '\n';
    } 
  }
//  for (auto &x : a) {
//    for (auto &y : x) {
//      cout << y << ' ';
//    }
//    cout << '\n';
//  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    priority_queue<tuple<long long, int, int>> q;
    for (auto&a : lines[x]) q.push({0, x, a});
    vector<vector<int>> vis(m + 1, vector<int>(25));
    i64 ans = 0;
    while (!q.empty()) {
      auto cur = q.top();
      q.pop();
      int s = get<1>(cur), line = get<2>(cur), dis = get<0>(cur);
      if (s == y) {
        ans = dis;
        break;
      }
//      cout << s << ' ' << line << endl;
      vis[s][line] = 1;
      for (auto &to : graph[s]){
        int ts = to.first, tl = to.second;
        if (vis[to.first][to.second]) continue;
        if (tl != line) {
          q.push({dis + time[{s, line}] + time[{ts, tl}], ts, tl});
        }
        else q.push({dis, ts, tl});
      }
    }
    cout << ans + w[x] + w[y]  << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  
  int t = 1;
  while (t--) solve();
  return 0;
}


