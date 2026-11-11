// GZ-S00343 杜泽煊
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,m;
int res[N]; 
vector<int> a(N);
int ans = 1;
int dp[N]; // dp[i] means 用i次操作最多能消除多少个差值 
inline void dfs(int step) {
	if(step == m) {
		vector<int> b(n + 1);
		for(int i = 1; i <= n; i ++) {
			b[i] = a[i];
		}
		for(int i = 0; i < m; i ++) {
			b[res[i]] ++;
		}
		sort(b.begin() + 1, b.end());
		for(int i = 1; i <= n; i ++) {
			int l = lower_bound(b.begin() + 1, b.end(), a[i]) - a.begin() - 1;
			int r = upper_bound(b.begin() + 1, b.end(), a[i]) - a.begin() - 1;
			ans = max(ans, r-l);
		}
		return;
	}
	for(int i = 1; i <= n; i ++) {
		res[step] = i;
		dfs(step + 1);
	}
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	a.resize(n + 1);
	vector<int> c(n + 1);
	bool flag = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int res = a[2] - a[1];
	for(int i = 2; i <= n; i ++) {
		if (a[i] - a[i-1] != res) {
			flag = 0;
		}
	}
	for(int i = 1; i < n; i ++) {
		c[i] = a[i + 1] - a[i];
		if(c[i] == 0) dp[0] ++; // eq in the begin
	}
	//第一档暴力 10pts
	if(n <= 5 && m <= 10) {
		dfs(0);
		cout << ans << "\n";
	} else if(flag == 1){ // 特殊性质 
		int cnt = 1;
		int ans = 0;
		for(int i = 1; i < n; i ++) {
			//cout << c[i] <<" ";
			if(m > c[i]) {
				m -= c[i];
				//cout << m <<" ";
				cnt ++;
				//cout << c[i+1] <<" ";
				c[i + 1] = c[i + 1] * cnt;
				//cout << c[i+1] <<" ";
				ans ++; 
			}
		}
		cout << ans << "\n";
	} else { // 背包dp 
		sort(a.begin() + 1, a.end());
		dp[0] = 1; // oneself
		// bag dp
		int zero = 0;
		for(int j = 1; j <= n; j ++) {
			for(int i = m; i >= 0; i --) {
				if(c[j] == 0) {
					continue;
				}
				if(c[j-1] == 0 && c[j]) {
					c[j] = c[j] * (zero + 1);
					zero = 0;
				}
				dp[i] = max(dp[i], dp[i - c[j]]);
				if(dp[i] == dp[i - c[j]]) { 
					c[j] --;
					if(c[j] == 0) {
						zero ++;
						dp[i] ++;
					}
				}
			} 
		}
		int ans = -1;
		for(int i = 1; i <= m; i ++) {
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
