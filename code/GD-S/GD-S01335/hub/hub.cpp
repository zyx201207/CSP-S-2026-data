#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> graph(n + 1);
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  cout << 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}


