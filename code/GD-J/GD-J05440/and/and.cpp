#include<bits/stdc++.h>
using namespace std;
int main {
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int dp[n+1][m+1];
	for(int i=1;i<=m;i++){
		dp[0][i]=1;
		dp[i][0]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]&dp[i][j-1])
		}
	}
	cout<<dp[n][m];
	return 0;
}
