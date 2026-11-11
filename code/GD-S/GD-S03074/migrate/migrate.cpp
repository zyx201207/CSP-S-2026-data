#include<bits/stdc++.h>
using namespace std;

#define int long long

void mian() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {0, 1}));
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n - i; j++) {
			int to = j + i;
			if(a[to] - a[j] <= d) {
				dp[j][to] = {1, 1};
				continue;
			}
			
			int min_ans = 4e18, cnt = 0;
			for(int k = j + 1; k < j + i; k++) {
				if(a[k] - a[j] > d) break;
				int now = dp[j][k].first + dp[k][to].first;
//				cout << "tmp " << now << ' ' << j << ' ' << k << ' ' << to << '\n';
				if(now < min_ans) {
					min_ans = now;
					cnt = dp[j][k].second * dp[k][to].second;
//					cout << cnt << '\n';
				} else if(now == min_ans) {
					cnt += dp[j][k].second * dp[k][to].second;
//					cout << cnt << '\n';
				}
			}
			dp[j][to] = {min_ans, cnt};
			if(cnt == 2) ans++;
		} 
	}
	
//	for(int i = 1; i <= n; i++) {
//		for(int j = i + 1; j <= n; j++) {
//			cout << dp[i][j].first << ' ' << dp[i][j].second << "     " ;
//		}
//		cout << '\n';
//	}
	
	cout << ans << '\n';
}

void md() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	int diff = a[2] - a[1];
	if(diff > d) {
		cout << 0 << '\n';
		return ;
	} else if(diff > d / 2) {
		cout << 0 << '\n';
		return ;
	} else if(diff <= d / 2 && diff > d / 3) {
		cout << n - 2 << '\n';
		return ;
	} else {
		cout << 0 << '\n';
		return ;
	}
}

signed main() {
	freopen("migrate4.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	if(c == 11 || c == 12) while(t--) md();
	else while(t--) mian();
	
	return 0;
}

/*
0 1
5 3
-3 0 2 3 4
*/
