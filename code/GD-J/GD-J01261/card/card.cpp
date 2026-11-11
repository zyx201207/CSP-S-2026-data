#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> ans(m + 1);
  for (int round = 1; round <= n; round++) {
    vector<int> cur(n + 5);
    int top = 1;
    unordered_map<int, int> pos;
    for (int i = round; i <= n; i++) {
      if (pos.count(a[i]) == 0) cur[top] = a[i], pos[a[i]] = top, top++;
      else top = pos[a[i]] + 1;
    }
    for (int i = 1; i < top; i++) ans[cur[i]]++;
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  freopen("card.out", "w", stdout);
  freopen("card.in", "r", stdin);
  
  int t = 1;
  while (t--) solve();
  return 0;   
}

