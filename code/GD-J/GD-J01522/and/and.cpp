#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], dp[5005][5005], ans;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		dp[i][0] = a[i];
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			dp[i][j] = max(dp[i][j - 1] & a[i], dp[i][j]);
		}
	}
	cout << dp[n][m];
	return 0;
}
 
