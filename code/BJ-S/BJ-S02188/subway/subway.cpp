#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
long long vis[600001], d[600001];
vector<pair<int, int> > g[600001];
vector<int> a[250001], t[250001];
int c, n, m, dd, qu;
int w[250001];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>dd>>qu;
	for (int i=1;i<=m;i++)
	{
		 cin>>w[i];
	}
	int nn=m;
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			int x, y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			nn++;
			g[nn].push_back({x, y});
			g[x].push_back({nn, y});
			if (j!=1)
			{
				g[nn-1].push_back({nn, 0});
				g[nn].push_back({nn-1, 0});
			}
		}
	}
	for (int i=1;i<=qu;i++)
	{
		int x, y;
		cin>>x>>y;
		memset(d, 0x3f, sizeof(d));
		memset(vis, 0, sizeof(vis));
		q.push({0, x});
		d[x]=0;
		while (!q.empty())
		{
			int u=q.top().second, l=q.top().first;
			q.pop();
//			cout<<u<<' '<<l<<endl;
			if (vis[u])
			{
				continue;
			}
			vis[u]=1;
			for (int i=0;i<g[u].size();i++)
			{
				int v=g[u][i].first, w=g[u][i].second;
				if (d[v]>d[u]+w)
				{
					d[v]=d[u]+w;
					q.push({d[v], v});
				}
			}
		}
		cout<<d[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
