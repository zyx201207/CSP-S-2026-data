#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) dp[i][1] = max(dp[i - 1][1], a[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]);
    }
  }
//  for (auto &x : dp) {
//    for (auto &y : x) cout << y << ' ';
//    cout << '\n';
//  }
  cout << dp[n][m] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  freopen("and.out", "w", stdout);
  freopen("and.in", "r", stdin);
  
  int t = 1;
  while (t--) solve();
  return 0;   
}

