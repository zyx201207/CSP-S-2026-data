#include<bits/stdc++.h>
using namespace std;
long long int dp[200005],a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1e18;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(j==1)
			{
				dp[1]=max(dp[1],a[i]);
			}
			if(dp[j-1]==-1e18)
			{
				continue;
			}
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}
