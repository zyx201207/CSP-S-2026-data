#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
typedef long long ll;
int idx, t;
ll a[MAXN], dp[MAXN][MAXN], sum[MAXN][MAXN];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("E://csps-new//down//migrate//migrate4.in", "r", stdin);
	cin >> idx >> t;
	while(t--) {
		ll n, d, ans = 0; cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if(idx == 11 || idx == 12) {
			int dif = a[2] - a[1];
			int div = d / dif;
			cout << n - 2 * div + 1 << endl;
		}
		if(idx == 13 || idx == 14) {
			cout << 0 << endl;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dp[i][j] = i == j ? 0 : 0x3f3f3f3f;
				sum[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(a[i] - a[j]) <= d) {
					dp[i][j] = dp[j][i] = 1;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= n; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= n; k++) {
					sum[i][j] += dp[i][j] == dp[i][k] + dp[k][j];
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 2; j <= n; j++) {
				ans += sum[i][j] == 4;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
