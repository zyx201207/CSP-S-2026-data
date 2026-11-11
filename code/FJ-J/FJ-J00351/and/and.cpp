#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;long long a[n+5],dp[n+5][m+1];;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][1]=a[i];
		for(int p=2;p<=m;p++)dp[i][p]=-1e9;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			for(int q=1;q<i;q++)
			{
				dp[i][j]=max(dp[i][j],(dp[q][j-1]&dp[i][1]));
			}
		}
	}
	long long ans=-1e9;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}