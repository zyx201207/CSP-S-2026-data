#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;

const int N = 2e6 + 6;

int cy, t, n, d, x[N];

namespace subtask1 {
  bool check() {
    return n <= 300;
  }

  int dp[333][333], cnt[333][333], ans;

  void solve() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = cnt[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (x[j] - x[i] <= d) {
          dp[i][j] = cnt[i][j] = 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = j + 1; k <= n; k++) {
          if ((dp[i][k] == 0 || dp[i][k] > dp[i][j] + dp[j][k]) && cnt[i][j] * cnt[j][k]) {
            dp[i][k] = dp[i][j] + dp[j][k];
            cnt[i][k] = cnt[i][j] * cnt[j][k];
          } else if (dp[i][k] == dp[i][j] + dp[j][k] && cnt[i][j] * cnt[j][k]) {
            cnt[i][k] += cnt[i][j] * cnt[j][k];
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ans += cnt[i][j] == 2;
      }
    }
    cout << ans << "\n";
  }
} // 24pts

void solve() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  //if (subtask1::check()) {
    subtask1::solve();
  //}
}

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> cy >> t;
  while (t--) {
    solve();
  }
  return 0;
}
