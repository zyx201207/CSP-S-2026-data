#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, m, a[N], dp[N][N];

signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	if(m == 1) {
		int mx = -1;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		cout << mx;
	}
	else if(m == 2) {
		int mx = -1;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			for(int j = 1; j < i; j++) {
				mx = max(mx, a[i] & a[j]);
			}
		}
		cout << mx;
	}
	else if(m == n) {
		cin >> a[1];
		int ans = a[1];
		for(int i = 2; i <= n; i++) {
			cin >> a[i];
			ans &= a[i];
		}
		cout << ans;
	}
	else{
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			dp[i][1] = a[i];
			for(int j = 1; j <= min(m, i); j++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] & a[i]);
			}
		}
		cout << dp[n][m];
	}
	return 0;
}

