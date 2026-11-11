#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200008],dp[200008];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	memset(dp,-0x3f,sizeof dp);
	
	dp[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(j==1)
				dp[j]=max(dp[j],a[i]);
			else
			{
				long long t=dp[j-1] & a[i];
				dp[j]=max(dp[j],t);
			}
		}
	}
	
	cout<<dp[m]<<'\n';
	return 0;
}
