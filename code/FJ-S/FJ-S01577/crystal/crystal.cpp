#include<bits/stdc++.h>
using namespace std;
int n, m, sum, a[5002], dp[5002][1002];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				dp[i][j]=max(dp[i][j-abs(a[i]-k)]+1, dp[i-1][j]);}}}
	cout << dp[n][m];
	return 0;
}
