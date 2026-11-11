#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long dis[305][305];
long long dp[305][305];
long long a[1000005];
void gogogo()
{
	long long ans=0;
	for(long long len=2;len<=n;len++)
	{
		for(long long i=1;i<=n;i++)
		{
			long long j=i+len-1;
			if(j>n)
			{
				break;
			}
			if(a[j]-a[i]<=d)
			{
				dis[i][j]=1;
				dp[i][j]=1;
				continue;
			}
			long long mindis=5e18;
			for(long long k=i+1;k<=j-1;k++)
			{
				if(dis[k][j]==1)
				mindis=min(mindis,dis[i][k]+dis[k][j]);
			}
			dis[i][j]=mindis;
			if(dis[i][j]==5e18)
			{
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=0;
			for(long long k=i+1;k<=j-1;k++)
			{
				if(mindis==dis[i][k]+dis[k][j]&&dis[k][j]==1)
				{
					dp[i][j]+=dp[i][k]*dp[k][j];
				}
			}
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dis[i][j]<<"\n";
			if(dp[i][j]==2)
			{
//				cout<<dis[i][j]<<' '<<i<<' '<<j<<"\n";
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
void dcsl()
{
	if((a[2]-a[1])*3>d&&(a[2]-a[1])*2<=d)
	{
		cout<<n-3<<"\n";
		return;
	}
	cout<<0<<'\n';
}
void solve()
{
	cin>>n>>d;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=300)
	{
		gogogo();
		return;
	}
	long long gc=a[2]-a[1];
	for(long long i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=gc)
		{
			break;
		}
		if(i==n)
		{
			dcsl();
			return;
		}
	}
	cout<<0<<"\n";
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,T;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
