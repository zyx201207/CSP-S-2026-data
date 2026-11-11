#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans,dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==m)
	{
		ans=a[1];
		for(long long i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==1)
	{
		for(long long i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==2)
	{
		for(long long i=1;i<n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	dp[1]=a[1];
	for(long long i=2;i<=n;i++)
	{
		for(long long j=m;j>1;j--)
		{
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
		dp[1]=max(dp[1],a[i]);
	}
	cout<<dp[m];
	return 0;
}
