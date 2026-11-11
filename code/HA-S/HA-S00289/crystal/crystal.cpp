#include<bits/stdc++.h>
using namespace std;;
int a[500005],n;
long long m,dp[1000000000000],ans;
int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=m;i>=1;i--)
		{
			for(int k=j;k<=n;k)
			{
				if(a[j]+i==a[k])
				{
					dp[i]+=max(dp[j]+i,dp[i]);
					
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=max(dp[i],ans);
	}
	cout<<ans;
	return 0;
} 
