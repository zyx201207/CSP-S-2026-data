#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],dp[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],dp[1][i]=max(dp[1][i-1],a[i]);
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++)
			dp[i][j]=max(dp[i][j-1],(dp[i-1][j-1]&a[j]));
	}
	cout<<dp[m][n];
	return 0;
}
