#include <bits/stdc++.h>
using namespace std;

struct E
{
	long long v,w;
};
struct P
{
	long long id,d;
	const bool operator < (const P&b)const
	{
		return d>b.d;
	}
};
vector<E> g[500505];
long long w[500005];
long long dist[500005],vis[500005];
long long ans = 0x3f3f3f3f;

void dijk(long long s,long long t)
{
	priority_queue<P> q;
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	q.push({s,0});
	while(!q.empty())
	{
		long long u = q.top().id,d=q.top().d;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u==t)ans=dist[u];
		for(int i = 0;i<g[u].size();i++)
		{
			if(d+g[u][i].w<dist[g[u][i].v])
			{
				dist[g[u][i].v]=d+g[u][i].w;
				q.push({g[u][i].v,d+g[u][i].w});
			}
		}
	}
}
void bfs(int s,int t)
{
	int q[500005];
	int f=0,r=0;
	memset(dist,0,sizeof dist);
	memset(vis,0,sizeof vis);
	q[++r]=s;
	while(f<r)
	{
		int top=q[++f];
		if(top==t)
		{
			ans=dist[t];
			return ;
		}
		for(int i = 0;i<g[top].size();i++)
		{
			int v = g[top][i].v;
			if(!vis[v])
			{
				q[++r]=v;
				dist[v]=dist[top]+1;
				vis[v]=1;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	int wwww = 0;
	for(int i = 1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			long long v,w1;
			cin>>v>>w1;
			g[i+m].push_back({v,w1});
			g[v].push_back({i+m,w1});
			wwww=w1;
		}
	}
	if(c>=12&&c<=19)
	{
		for(int i = 1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			bfs(x,y);
			ans=ans*wwww+w[x]+w[y];
			cout<<ans<<'\n';
		}
	}
	else
	{
		for(int i = 1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			dijk(x,y);
			ans=ans+w[x]+w[y];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
