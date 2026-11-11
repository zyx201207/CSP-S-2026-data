#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int c,n,m,dis,q,w[N],d[N],vis[N];
struct edge{
	int v,w;
};
vector<edge>e[N];
void dijkstra(int s)
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int>>q;
	q.push({0,s});d[s]=0;
	while(q.size())
	{
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed:e[u])
		{
			int v=ed.v,w=ed.w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dis>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			e[i+m].push_back({a,t});
			e[a].push_back({i+m,t});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<w[x]+d[y]+w[y]<<"\n";
	}
	return 0;
}
