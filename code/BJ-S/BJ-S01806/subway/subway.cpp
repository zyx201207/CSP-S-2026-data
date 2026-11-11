#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=8e6+5;
struct node
{
	int v,w;
	friend bool operator <(node x,node y)
	{
		return x.w>y.w;
	}
};
vector<node> e[N];
int dis[N],vis[N];
void dij(int x)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<node> q;
	q.push({x,0});
	dis[x]=0;
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto it:e[u])
		{
			int v=it.v,w=it.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
		e[i].push_back({i+m,w});
		e[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			e[v+m].push_back({v+m*3*i,w});
			e[v+m*3*i].push_back({v+m,w});
			
			e[m*4+i].push_back({v+m*3*i,0});
			e[v+m*3*i].push_back({m*4+i,0});
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<dis[v]<<"\n";
	}
	return 0;
}
