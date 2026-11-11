#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int dp[5005], dp2[5005], a[5005];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		int n, d, cnt = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) dp[j] = 1e18;
			memset(dp2, 0, sizeof(dp2));
			dp[i] = 0;
			for(int j = i + 1;j <= n;j++) {
				for(int k = j - 1;k >= i;k--) {
					if(a[j] - a[k] > d) break;
					dp[j] = min(dp[j], dp[k] + 1);
				}
				//cout << dp[j] << " ";
			}
			//cout << "\n";
			for(int j = i + 1;j <= n;j++) {
				for(int k = j - 1;k >= i;k--) {
					if(a[j] - a[k] > d) break;
					if(dp[j] == dp[k] + 1) dp2[j]++;
				}
				if(dp2[j] == 2) {
					//cout << i << " " << j << " " << dp[j] << "\n";
					cnt++; 
				}
			}
			//if(i == 1) cout << a[5] - a[2] << "\n";
		}
		cout << cnt << "\n";
	}
	return 0;
}
//7 666666666666666663
//-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
