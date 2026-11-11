#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;
};
vector<node> e[1000010];
int dis[1000010],vis[1000010],w[500010];
priority_queue<pair<int,int> > q;
void add(int u,int v,int w)
{
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
int dij(int st,int ed)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	q.push({0,st});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(auto x:e[u])
		{
			int v=x.v,w=x.w;
			if(vis[v])continue;
			vis[v]=1;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
	return dis[ed];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
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
			add(a,i+m,t);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<dij(u,v)+w[u]+w[v]<<endl;
	}
	return 0;
}