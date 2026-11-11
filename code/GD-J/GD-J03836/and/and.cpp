#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2005];
int dp[2005][2005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i][1]=max(dp[i-1][1],a[i]);
		for(int j=2;j<=min(i,m);j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
