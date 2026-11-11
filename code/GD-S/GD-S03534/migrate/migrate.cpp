#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;
int n, mxp[N], dp[N], dpcnt[N];
ll d, a[N];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		mxp[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0, dpcnt[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			dp[j] = 2e9, dpcnt[j] = 0;
			for (int k = max(i, mxp[j]); k < j; k++) {
				if (dp[k] + 1 < dp[j]) {
					dp[j] = dp[k] + 1;
					dpcnt[j] = dpcnt[k];
				} else if (dp[k] + 1 == dp[j]) {
					dpcnt[j] += dpcnt[k];
				}
			}
			if (dpcnt[j] == 2) ++ans;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
