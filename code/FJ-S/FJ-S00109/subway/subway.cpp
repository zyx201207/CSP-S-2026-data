#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,q,k[N],d,c,w[5005];
struct P{
	int a,t,id;
};
vector<P> e[5005];
int dij(int x,int y)
{
	int dis[500005];
	int vis[500005];
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	dis[x]=0;
	q.push({dis[x],x});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].a,di=e[u][i].t;
			if(dis[v]>dis[u]+di)
			{
				dis[v]=dis[u]+di;
				q.push({dis[v],v});
			}
		}
	}
	return dis[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>e[i][j].a>>e[i][j].t;
			e[i][j].id=i;
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dij(x,y)+w[y]<<endl;
	}
	return 0;
}
