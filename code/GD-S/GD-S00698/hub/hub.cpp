#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
struct edge
{
	int to,nxt;
}g[N*2];
int head[N],tot;
void add(int x,int y)
{
	g[++tot]={y,head[x]};
	head[x]=tot;
}
int Tid,n,k;
bool vis[N];
bool can[N];
void dfs(int x,int fa)
{
	vis[x]=1;
	for(int i=head[x];i;i=g[i].nxt)
	{
		int v=g[i].to;
		if(v==fa)	continue;
		if(can[v])	dfs(v,x);
	}
}
int dis[N];
void dfs2(int x,int fa)
{
	for(int i=head[x];i;i=g[i].nxt)
	{
		int v=g[i].to;
		if(v==fa)	continue;
		if(dis[v]>dis[x]+1)
		{
			dis[v]=dis[x]+1;
			dfs2(v,x);
		}
	}
}
int ans=0;
void solve()
{
	ans=1e9+5;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		head[i]=0;
	}
	tot=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<(1<<n);i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			vis[j]=0;
			dis[j]=1e9+5;
			if(i&(1<<(j-1)))
			{
				cnt++;
				can[j]=1;
			}
			else
			{
				can[j]=0;
			}
		}
		if(cnt!=k)	continue;
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&can[j])
			{
				dfs(j,0);
				cnt++;
			}
		}
		if(cnt>2)	continue;
		for(int j=1;j<=n;j++)
		{
			if(can[j])
			{
				dis[j]=0;
				dfs2(j,0);
			}
		}
		int max1=0;
		for(int j=1;j<=n;j++)
		{
			max1=max(max1,dis[j]);
		}
		ans=min(ans,max1);
	}
	printf("%d\n",ans);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	scanf("%d%d",&Tid,&T);
	while(T--)	solve();
	return 0;
}

