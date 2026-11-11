#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d;
int dp[N], x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int cnt = 1;
			for (int j = i-1; j >= 0; j--) {
				if (x[i]-x[j] <= d) {
					if (dp[i] == 0) {
						dp[i] = dp[j] + 1;
						continue;
					}
					if (dp[i] == dp[j]+1) cnt++;
					else if (dp[i] > dp[j]+1) {
						dp[i] = dp[j]+1;
						cnt = 1;
					}
				}
				else break;
			}
			if (cnt == 2) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
