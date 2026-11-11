#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[200005];
long long dp[200005][35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=31;i++) ans*=2;
	ans--;
	for(long long i=1;i<=n;i++)
	{
		long long k=a[i];
		for(long long j=0;j<=30;j++)
		{
			if(k%2==1) dp[i][j]=1;
			k/=2;
		}
	}
	for(long long i=0;i<=30;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			dp[n+1][i]+=dp[j][i];
		}
	}
	for(long long i=30;i>=0;i--)
	{
		if(dp[n+1][i]>=m)
		{
			for(long long j=1;j<=n;j++)
			{
				if(dp[j][i]==1) ans=ans&a[j];
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}
