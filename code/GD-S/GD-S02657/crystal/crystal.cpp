#include<bits/stdc++.h>
using namespace std;
int a[114514];
int dp[5001][5001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((a[i]-a[i-1])*dp[i-1][j]<=j)dp[i][j]=max(dp[i-1][j],dp[i-1][j-(a[i]-a[i-1])*dp[i-1][j]]+1);
			else dp[i][j]=dp[i-1][j];
		}
	}
	
	

	cout<<dp[n][m];
	return 0;
	
}
