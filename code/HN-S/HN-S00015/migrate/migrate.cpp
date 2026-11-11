#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n;
long long x[N],d;
long long dp[5005][5005],vis[5005][5005];
void work()
{
	cin>>n>>d;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i];
	}
}
void A()
{
	int ch=x[2]-x[1];
	if(d/ch<2)
	{
		cout<<0<<'\n';
	}
	else
	{
		cout<<max(n-(d*2ll)/ch+1ll,0ll)<<'\n';
	}
}
void BF()
{
	int ans=0;
	memset(dp,0,sizeof(dp));
	memset(vis,0x3f,sizeof(vis));
	for(int i=1;i+1<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(x[j]-x[i]<=d)dp[i][j]=1,vis[i][j]=1;
		}
	}
	for(int i=1;i+2<=n;++i)
	{
		for(int j=i+2;j<=n;++j)
		{
			for(int k=i+1;k<j;++k)
			{
				if(vis[i][k]+vis[k][j]==vis[i][j])
				{
					dp[i][j]+=dp[i][k]*dp[k][j];
				}
				else if(vis[i][k]+vis[k][j]<vis[i][j])
				{
					dp[i][j]=dp[i][k]*dp[k][j];
					vis[i][j]=vis[i][k]+vis[k][j];
				}
			}
		}
	}
	for(int i=1;i+2<=n;++i)
	{
		for(int j=i+2;j<=n;++j)
		{
			if(dp[i][j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
void B()
{
	if(n>3)
	{
		cout<<n-2<<'\n';
	}
	else cout<<0;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		work();
		if(n<=3)
		{
			cout<<0<<'\n';
		}
		else if(c<=10)
		{
			BF();
		}
		else if(c<=12)
		{
			A();
		}
		else if(c<=14)
		{
			B();
		}
		else
		{
			BF();
		}
	}
	return 0;
}
