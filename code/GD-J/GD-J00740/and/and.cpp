#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int ad(int x, int y) {
	int a[500] = {0}, b[500] = {0}, c[500] = {0};
	int cnt = 0;
	while(x != 0) {
		a[++cnt] = x % 2;
		x /= 2;
	}
	int cnty = 0;
	while(y != 0) {
		b[++cnty] = y % 2;
		y /= 2;
	}
	for(int i = 1; i <= max(cnt, cnty); i++) {
		if(a[i] == 1 && b[i] == 1) c[i] = 1;
		else c[i] = 0;
	}
	
	int ans = 0;
	int pw = 1;
	for(int i = 1; i <= max(cnt, cnty); i++) {
		ans += pw * c[i];
		pw *= 2;
	}
	return ans;
}

int ar[200010];
int dp[200010][25];//前i个数中选了j个的最大值 
//int ans;
//bool vis[200010];

//void dfs(int sum, int nw, int num
//	if(num == m) {
//		ans = max(ans, sum);
//		return;
//	}
//	
//}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	
	if(m == n) {
		int ans = ar[1];
		for(int i = 2; i <= n; i++) {
			ans = ad(ans, ar[2]);
		}
		cout << ans;
		return 0;
	}
	
	int maxn = -1;
	for(int i = 1; i <= n; i++) {
		if(ar[i] > maxn) maxn = ar[i];
		dp[i][1] = maxn;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= min(i, m); j++) {
			int c = 0;
			if(i - 1 >= j) c = dp[i - 1][j];
			dp[i][j] = max(c, ad(dp[i][j - 1], ar[i]));
		}
	}
	cout << dp[n][m];
	
	return 0;
}
