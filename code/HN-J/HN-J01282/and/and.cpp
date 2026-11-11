#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[2005][2005],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>dp[i][1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int t=2;t<=m;t++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i][t]=max(dp[i][t],dp[j][t-1]&dp[i][1]);
			
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,dp[i][m]);
	}
	cout<<maxn; 
	return 0;
}
