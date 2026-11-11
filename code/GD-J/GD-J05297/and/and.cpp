#include <bits/stdc++.h>
using namespace std; 
#define int long long

int n, m, dp[2010][2010][2];
vector<int> a;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	a = vector<int>(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	if(n <= 2000) {
		for(int i = 1; i <= n; i++) dp[i][1][1] = a[i];
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j <= i && j <= m; j++) {
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
				if(j > 1) dp[i][j][1] = max(dp[i - 1][j - 1][0] & a[i], dp[i - 1][j - 1][1] & a[i]);
			}
		}
		cout << max(dp[n][m][0], dp[n][m][1]);
		return 0;
	}
	for(int i = 30; i >= 0; i--) {
		vector<int> vis;
		vis.push_back(0);
		int cnt = 0, len = a.size() - 1;
		for(int j = 1; j <= len; j++) {
			if(a[j] & (1 << i)) vis.push_back(a[j]), cnt++;
		}
		if(cnt >= m) a = vector<int>(), a = vis;
//		if(i == 4) for(int i = 1; i <= m; i++) cout << a[i] << "\n";
		if(a.size() == m) break;
	}
	int ans = (1ll << 31) - 1;
	for(int i = 1; i <= m; i++) {
		ans &= a[i];
//		if(ans == 0) cout << i << "|||\n";
//		cout << a[i] << "\n";
	}
	cout << ans;
	return 0;
}
