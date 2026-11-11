#include<bits/stdc++.h>
using namespace std;
long long dp[200000+5],a[200000+5];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		long long maxn=-1e18;
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
			{
				long long t=a[i]&a[j];
				maxn=max(maxn,t);
			}
		cout<<maxn;
		return 0;
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0]=pow(2,30)-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
