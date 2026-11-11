#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005];
int dp[20005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	dp[1][1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
