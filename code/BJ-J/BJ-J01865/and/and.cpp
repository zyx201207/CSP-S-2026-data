#include<bits/stdc++.h>
using namespace std;
// 50 points

const int N = 2e3+5;
int n, m;
int a[N], dp[N][N]; //滚动
//物品数  n  总重量 m
//物品编号 i  重量  1  价值a[i]
//dp[i][j] 考虑到物品 i，重量必须为 j，最大价值

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=0; i<=n; i++){
		dp[i][0] = INT_MAX;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] & a[i]);
//			cout<<dp[i][j]<<' ';		
		}
//		cout<<'\n';
	}
	cout<<dp[n][m];
	return 0;
}
