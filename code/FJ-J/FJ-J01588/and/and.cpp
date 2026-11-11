#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans = -1e18, dp[2005];
int a[200005];
void dfs(int i, int cnt, int yv){
	if (i == n && cnt + 1 < m)return ;
	if (i > n + 1)return ;
	if (cnt == m){
		ans = max(ans, yv);
		return ;
	}
	dfs(i + 1, cnt + 1, yv & a[i]);
	dfs(i + 1, cnt, yv);
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n <= 20){
		dfs(1, 0, 0b111111111111111111111111111111111111111111111111111111111111111);
		cout << ans;
	}
	else if (m == n){
		int b = a[1];
		for (int i = 2; i <= n; i++){
			b = b & a[i];
		}
		cout << b;
	}
	else if (n <= 2000){
		for (int i = 1; i <= n; i++){
			dp[i] = 0;
		}
		dp[0] = 0b111111111111111111111111111111111111111111111111111111111111111;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j < i; j++){
				dp[j] = max(dp[j], dp[j - 1] & a[j]);
			}
		}
		cout << dp[n];
	}
	return 0;
}
