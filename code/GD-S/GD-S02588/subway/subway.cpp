#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[20005],a[505][20005],k[505],t[505][20005],x,y,cnt,dis[20005];
priority_queue <pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > p;
bool flag[505];
vector <pair<int,int> > e[20005];
void dijkstra(int s)
{
	for (int i=1;i<=m;i++)
		dis[i]=0x3f3f3f3f3f3f3f;
	memset(flag,0,sizeof(flag));
	dis[s]=0;
	p.push(make_pair(0,s));
	while (!p.empty())
	{
		int u=p.top().second;
		p.pop();
		if (flag[u])
			continue;
		flag[u]=true;
		for (int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].first;
			long long w=e[u][i].second;
			if (dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				p.push(make_pair(dis[v],v));
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[a[i][j]][i];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k[i];j++)
		{
			for (int f=j+1;f<=k[i];f++)
			{
				e[a[i][j]].push_back(make_pair(a[i][f],t[a[i][j]][i]+t[a[i][f]][i]));
				e[a[i][f]].push_back(make_pair(a[i][j],t[a[i][j]][i]+t[a[i][f]][i]));
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
