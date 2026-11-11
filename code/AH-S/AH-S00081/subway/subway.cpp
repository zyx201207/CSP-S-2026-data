#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500505],t[500505],dis[500505];
bool vis[500505];
struct mi{
	int v,ww;
};
vector<mi> g[500505];
void dijkstra(int s,int tt)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int>> pq;
	pq.push({0,s});
	dis[s]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u])
		{
			int v=e.v,ww=e.ww;
			if(dis[u]+ww<dis[v])
			{
				dis[v]=dis[u]+ww;
				pq.push({-1*dis[v],v});
			}
		}
	}
	cout<<dis[tt]+w[s]+w[tt]<<'\n';
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int tt;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>tt>>t[j];
			g[tt].push_back({i+500000,t[j]}),g[i+500000].push_back({tt,t[j]});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int s,tt;
		cin>>s>>tt;
		dijkstra(s,tt);
	}
	return 0;
}
