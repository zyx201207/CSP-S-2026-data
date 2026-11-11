#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int dp[5010][5010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		dp[i][1]=max(k,dp[i-1][1]);
		for(int j=2;j<=m and j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&k);
		}
	}
	cout<<dp[n][m];
}
