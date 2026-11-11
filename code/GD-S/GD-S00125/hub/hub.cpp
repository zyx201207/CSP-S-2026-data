#include<bits/stdc++.h>
using namespace std;
const int N=5;
const int M=10;
int u[N+5],v[N+5];
bool vis[N+5];
bool vise[N+5];
struct edge
{
	int nxt;
	int to;
}e[M+5];
int cnt;
int head[N+5];
void addedge(int u,int v)
{
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int n,k;
int s[N+5];
void init_set(int n)
{
	for(int i=1;i<=n;i++)
	{
		s[i]=i;
	}
}
int find_set(int x)
{
	if(x!=s[x])
	{
		s[x]=find_set(s[x]);
	}
	return s[x];
}
void merge_set(int x,int y)
{
	x=find_set(x);
	y=find_set(y);
	if(x!=y)
	{
		s[x]=y;
	}
}
int t[N+5];
int ans;
bool ee[N+5][N+5];
int dis[N+5];
void findlen(int u,int f)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=f)
		{
			dis[v]=dis[u]+1;
			findlen(v,u);
		}
	}
}
void dfs(int dep,int now)
{
	if(now>k)
	{
		init_set(n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j && vis[i] && vis[j] && ee[i][j])
				{
					merge_set(i,j);
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				continue;
			}
			sum+=(i==s[i]);
		}
		if(sum>2)
		{
			return ;
		}
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				continue;
			}
			dis[i]=0;
			findlen(i,0);
			int t=0x3f3f3f3f;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j])
				{
					continue;
				}
				t=min(t,dis[j]);
			}
			maxx=max(maxx,t);
		}
		ans=min(ans,maxx);
		return ;
	}
	if(dep>n)
	{
		return ;
	}
	else
	{
		if(now<=k)
		{
			vis[dep]=1;
			dfs(dep+1,now+1);
			vis[dep]=0;
		}
		dfs(dep+1,now);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			ee[u[i]][v[i]]=ee[v[i]][u[i]]=1;
			addedge(u[i],v[i]);
			addedge(v[i],u[i]);
		}
		ans=0x3f3f3f3f;
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}
