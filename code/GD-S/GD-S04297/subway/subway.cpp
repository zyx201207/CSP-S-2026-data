#include<bits/stdc++.h>
using namespace std;
int w[500010],dist[500510],vis[500510];
struct edge
{
	int v,d;
};
struct point
{
	int d,u;
};
vector<edge>e[500510];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,q;
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			e[a].push_back({i+m,t});
			e[i+n].push_back({a,t});
		}
	}
	while(q--)
	{
		int u,b;
		memset(dist,0x3f3f3f3f,sizeof(dist));
		memset(vis,0,sizeof(vis));
		cin>>u>>b;
		priority_queue<point,vector<point>,less<point> >q;
		dist[u]=0;
		q.push({0,u});
		while(!q.empty())
		{
			point t=q.top();
			q.pop();
			int u=t.u,dis=t.d;
			if(vis[u]=1)continue;
			vis[u]=1;
			for(edge i:e[u])
			{
				int v=i.v,distance=i.d;
				if(dis+distance<dist[v])
				{
					dist[v]=dis+distance;
					q.push({dist[v],v});
				}
			}
		}
		cout<<dist[b];
	}
	return 0;
}
