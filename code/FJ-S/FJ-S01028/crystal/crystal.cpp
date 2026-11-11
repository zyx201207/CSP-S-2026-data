#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, ans;
ll m1, m, a[N], dp[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; m1 = m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a, a + n);
	if (n % 2) {
		int tot = a[n / 2 + 1];
		for (int i = 1; i <= n; ++i) {
			if (abs(a[i] - tot) <= m) {
				dp[i] = dp[i - 1] + 1;
				m -= abs(a[i] - tot);
			} else {
				dp[i] = dp[i - 1] + (a[i] == tot);
			}
		}
		ans = dp[n - 1];
	} else {
		int tot = a[n / 2];
		for (int i = 1; i <= n; ++i) {
			if (abs(a[i] - tot) <= m) {
				dp[i] = dp[i - 1] + 1;
				m -= abs(a[i] - tot);
			} else {
				dp[i] = dp[i - 1] + (a[i] == tot);
			}
		}
		ans = dp[n - 1];
		tot = a[n / 2 + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			if (abs(a[i] - tot) <= m1) {
				dp[i] = dp[i - 1] + 1;
				m1 -= abs(a[i] - tot);
			} else {
				dp[i] = dp[i - 1] + (a[i] == tot);
			}
		}
		ans = max(1LL * ans, dp[n - 1]);
	}
	cout << ans;
	return 0;
}