#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, m;
int a[maxn];
int dp[2005][2005];
int su_p[maxn], su_b[maxn];
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][1] = a[i];
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans << flush;
		return 0;
	}
	if (m == n - 1) {
		su_p[1] = a[1];
		for (int i = 2; i <= n; i++) {
			su_p[i] = (su_p[i - 1] & a[i]);
		}
		su_b[n] = a[n];
		for (int i = n - 1; i >= 1; i--) {
			su_b[i] = (su_b[i + 1] & a[i]);
		}
		int ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans = max (ans, (su_p[i] & su_b[i + 2]));
		}
		cout << ans << flush;
		return 0;
	}
	if (n <= 2000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 2; j <= min (i, m); j++) {
				for (int k = 1; k < i; k++) {
					dp[i][j] = max (dp[i][j], (dp[k][j - 1] & a[i]));
					//				cout << i << " , " << j << " | " << (dp[k][j - 1] & a[i]) << " | " << dp[k][j - 1] << " " << dp[i][j] << endl;
				}
			}
		}
		int ans = 0;
		for (int i = m; i <= n; i++) {
			ans = max (ans, dp[i][m]);
			//		cout << i << " " << dp[i][m] << endl;
		}
		cout << ans << flush;
	} else {
		sort (a + 1, a + n + 1);
		cout << a[n - m + 1] << flush;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
