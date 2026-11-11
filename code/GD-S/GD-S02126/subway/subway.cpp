#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int c,n,m,d,q,w[N],dist[505][505];
bool vis[505];
vector<int> a[N],t[N];
vector<pair<int,int> > sub[N];
struct node
{
	int u,w;
	bool operator < (const node& other) const {return w>other.w;}
};
void dijkstra(int s)
{
	memset(dist[s],0x3f,sizeof(dist[s]));
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({s,0}),dist[s][s]=0;
	while (!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=1;i<a[u].size();i++)
		{
			for (auto e:sub[a[u][i]])
			{
				int v=e.first,w=t[u][i]+e.second;
				if (vis[v]) continue;
				if (dist[s][u]+w<dist[s][v])
				{
					dist[s][v]=dist[s][u]+w;
					q.push({v,dist[s][v]});
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
		cin >> w[i];
	int k;
	for (int i=1;i<=n;i++)
	{
		cin >> k;
		a[i].resize(k+1),t[i].resize(k+1);
		for (int j=1;j<=k;j++)
		{
			cin >> a[i][j] >> t[i][j];
			sub[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for (int i=1;i<=n;i++)
		dijkstra(i);
	int u,v;
	while (q--)
	{
		cin >> u >> v;
		int mn=1e18,x,y;
		for (auto e1:sub[u])
		{
			x=e1.first;
			for (auto e2:sub[v])
				y=e2.first,mn=min(mn,dist[x][y]+e1.second+e2.second);
		}
		cout << mn+w[u]+w[v] << '\n';
	}
	return 0;
}
