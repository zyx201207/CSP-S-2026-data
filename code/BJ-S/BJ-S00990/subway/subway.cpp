#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 507;

int c, n, m, d, q, w[N*N];
int k, a[N*N][30], t[N*N][30];

struct node{
	int v, w;
};
vector<node> G[N*N];
bool operator < (node x, node y)
{
	return x.w > y.w;	
}

int dis[N*N], vis[N*N];
int Dijkstra(int st, int nd)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	dis[st] = 0;
	q.push({st, 0});
	
	while(!q.empty())
	{
		node cur = q.top();
		q.pop();
		
		int u = cur.v;
		if(vis[u]) continue;
		vis[u] = 1;
		
		for(auto e : G[u])
		{
			int v = e.v , w = e.w;
			if(!vis[v] && dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
	//cout<<st<<":\n";
	//for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
	//cout<<"\n";
	
	return w[st] + w[nd] + dis[nd];
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][j]>>t[i][j];
			
		for(int x=1;x<=k;x++)
		{
			for(int y=x+1;y<=k;y++)
			{
				int u = a[i][x], v = a[i][y];
				int w = t[i][x] + t[i][y];
				G[u].push_back({v, w});
				G[v].push_back({u, w});
			}
		}
	}
	while(q--)
	{	
		int x, y;
		cin>>x>>y;
		cout<<Dijkstra(x, y)<<"\n";
	}
	
	
	return 0;
}
