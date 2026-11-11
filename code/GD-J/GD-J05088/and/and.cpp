#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5001][1001];
int n, m;
int a[100001];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int maxn = 0;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		maxn = max(maxn, a[i]);
		dp[i][1] = a[i];
	}
	if(m == 1){
		cout << maxn;
		return 0;
	}
	if(n == m){
		int sum = a[0];
		for(int i = 1; i < n; ++i)sum &= a[i];
		cout << sum;
		return 0;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] & a[i]);
		}
	}
	cout << dp[n - 1][m - 1];
	return 0;
}
