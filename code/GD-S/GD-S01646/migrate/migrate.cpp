#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2000005;
int c,t,n,d;
int x[MAXN],dis[MAXN],cnt[MAXN];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void dfs(int u,int sum)
{
	if(sum>dis[u])
	{
		return ;
	}
	else if(sum==dis[u])
	{
		cnt[u]++;
	}
	else if(sum<dis[u])
	{
		dis[u]=sum;
		cnt[u]=1;
	}
	for(int i=n;i>u;i--)
	{
		if(x[i]-x[u]<=d)
		{
			dfs(i,sum+1);
		}
	}
	return ;
}
void work()
{
	n=read(),d=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	if(c==11||c==12)
	{
		int D=x[2]-x[1];
		int newd=d-d%D;
		if(newd==2*D)
		{
			printf("%lld\n",n-3);
		}
		else
		{
			printf("0\n");
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[j]=1e18;
			cnt[j]=0;
		}
		dis[i]=0,cnt[i]=1;
		dfs(i,0);
		for(int j=i+1;j<=n;j++)
		{
			if(cnt[j]==2) ++ans;
		}
	}
	printf("%lld\n",ans);
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		work();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
