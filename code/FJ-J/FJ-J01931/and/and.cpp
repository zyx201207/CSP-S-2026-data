#include <bits/stdc++.h>
using namespace std;
int dp[70001][2001], a[2001], n, m;
bool cmp(int a,int b){
	return a>b;
} 
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	//ios::sync_with_stdio(0), cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++){
		dp[i][1]=max(dp[i-1][1], a[i]);
		for(int j=2; j<=min(i, m); j++){
			if(dp[i-1][j]!=0)dp[i][j]=max(dp[i-1][j-1]&a[i], dp[i-1][j]);
			else dp[i][j]=dp[i-1][j-1]&a[i];
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
