#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int dp[2008611][2];//0 zuiduanlu  1 fanan
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x*=10,x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
int x[2008611];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,t,n,d,ans=0;
	id=read(),t=read();
	while(t--)
	{
		ans=0;
		n=read(),d=read();
		for(int u=1;u<=n;u++)
		x[u]=read(),dp[u][1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int u=i+1;u<=n;u++)
			dp[u][0]=1e18,dp[u][1]=0;
			dp[i][1]=1,dp[i][0]=0;
			for(int u=i+1;u<=n;u++)
			{
				for(int p=u-1;p>=i&&x[u]-x[p]<=d;p--)
				{
					if(dp[p][0]+1<dp[u][0])
					dp[u][0]=dp[p][0]+1,dp[u][1]=dp[p][1];
					else if(dp[p][0]+1==dp[u][0])
					dp[u][1]+=dp[p][1];
				}
				if(dp[u][1]==2)
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
