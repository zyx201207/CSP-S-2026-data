#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long c, t, ans;
long long n, x[501], d;
void solve() {
	cin >> n >> d;
	cin >> x[1];
	for(int i = 2;i <= n;i ++) {
		cin >> x[i];
		if(x[1] < 0) {
			x[i] += (-x[1]);
		}
	}
	x[1] = 0;
	int dp[310][310];
	int cnt[310][310];
	for(int i = 1;i <= 301; i ++) {
		for(int j = i + 1;j <= 301; j ++) {
			if(x[j] - x[i] <= d) {
				dp[i][j] = 1;
				cnt[i][j] = 1;
			} 
			else dp[i][j] = 1e8;
		}
	}
	for(int i = 1;i <= n - 1;i ++) {
		for(int j = 1; j <= n - i; j ++) {
			for(int k = j + 1; k < j + i; k ++) {
				long long d1 = x[j + i] - x[k], d2 = x[k] - x[j];
				if(d1 <= d && d2 <= d) {
					if(dp[j][k] + dp[k][j + i] == dp[j][j + i]) cnt[j][j + i] ++;
					if(dp[j][k] + dp[k][j + i] < dp[j][j + i]) {
						if(cnt[j][k] == -1 || cnt[k][j + i ] == -1) cnt[j][j + i] = -1;
						else cnt[j][j + i] += (cnt[j][k] * cnt[k][j + i]);
						if(cnt[j][j + i] > 2) cnt[j][j + i] = -1;
						dp[j][j + i] = dp[j][k] + dp[k][j + i];
					}
				}
			}
		}
	} 
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(cnt[i][j] == 2) ans ++;
		}
	}
	cout << ans << endl;
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --) {
    	if(c <= 6) solve();
	}
	return 0;
}
