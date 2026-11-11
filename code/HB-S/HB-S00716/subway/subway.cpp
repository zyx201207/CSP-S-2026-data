#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int c,n,m,y,q,w[500005],a[500005],t[500005],k;
long long d[5005][5005];
struct edge
{
	int v,w;
};
vector<edge> e[5005];
int u,v;
void dijkstra(int s)
{
	for(int i=1;i<=m;i++)
	{
		d[s][i]=LLONG_MAX;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	d[s][s]=0;
	while(q.size())
	{
		int nd=q.top().first,u=q.top().second;
		q.pop();
		if(nd>d[s][u])
		{
			continue;
		}
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i].v,w=e[u][i].w;
			if(d[s][u]+w<d[s][v])
			{
				d[s][v]=d[s][u]+w;
				q.push({d[s][v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> y >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int x=1;x<=n;x++)
	{
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> a[j] >> t[j];
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				e[a[i]].push_back({a[j],t[i]+t[j]});
				e[a[j]].push_back({a[i],t[i]+t[j]});
			}
		}
	}
	while(q--)
	{
		cin >> u >> v;
		if(!d[u][v])
		{
			dijkstra(u);
		}
		cout << w[u]+w[v]+d[u][v] << "\n";
	}
	return 0;
}
