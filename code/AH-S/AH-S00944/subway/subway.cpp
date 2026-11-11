#include<bits/stdc++.h>
using namespace std;
const int M=5e5+1005;
const long long inf=1e18;
typedef long long ll;
int aaa,bbb,b,c,ccc;
int e,n,m,d,q,x;
ll dist[M],a[M],dp[1005][1005];
bool vis[M];
struct edge
{
	int to,w;
};
vector<edge> g[M];
struct node
{
	int v;
	ll dis;
	bool operator<(const node &o)const
	{
		dis>o.dis;
	}
};
priority_queue<node> pq;
void dijkstra(int x,int y)
{
	for(int i=1;i<=y;i++)
	{
		dist[i]=inf;
		vis[i]=0;
	}
	dist[x]=0;
	pq.push({x,0});
	while(!pq.empty())
	{
		node t=pq.top();
		pq.pop();
		int u=t.v;
//		if(vis[u])
//		{
//			continue;
//		}
//		vis[u]=1;
		for(auto p:g[u])
		{
			int v=p.to,dd=p.w;
			if(dist[u]+dd<dist[v])
			{
				dist[v]=dist[u]+dd;
				pq.push({v,dist[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>e>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>b>>c;
			g[m+i].push_back({b,c});
			g[b].push_back({m+i,c});
		}
	}
	if(q>2000)
	{
		for(int i=1;i<=m;i++)
		{
			dijkstra(i,m+n);
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=dist[j];
			}
		}
		while(q--)
		{
			cin>>aaa>>bbb;
			cout<<dp[aaa][bbb]+a[aaa]+a[bbb]<<'\n';
		}
		return 0;
	}
	while(q--)
	{
		cin>>aaa>>bbb;
		dijkstra(aaa,m+n);
		cout<<dist[bbb]+a[aaa]+a[bbb]<<'\n';
	}
	return 0;
} 
