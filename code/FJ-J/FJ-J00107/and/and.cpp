#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,dp[200][200];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dp[i][1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(int p=1;p<=i;p++){
				dp[i][j]=max(dp[i][j],dp[i-p][j-1]&dp[i][1]);
			}
		}
	}
	cout<<dp[n][m];
	
}