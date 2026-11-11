#include <bits/stdc++.h>
using namespace std;
const int N=5e5+550;
struct node
{
	int dis,x;
	bool pd;
	bool operator >(const node &x) const
	{
		return dis>x.dis;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
int w[N],k[N],t[505][N],a[505][N];
int pd[N],vis[N],more[N];
int tot;
vector<int> g[N];
int dis[N];
void dijkstra(int x)
{
	dis[x]=w[x]+t[pd[x]][x];
	q.push({0,x,0});
	while (!q.empty())
	{
		int u=q.top().x,zhong=q.top().pd;
		q.pop();
		if (vis[u]==tot)
		{
			continue;
		}
		vis[u]=tot;
		if (zhong)
		{
			for (int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if (dis[v]>dis[u]+t[pd[u]][v]+t[pd[v]][v])
				{
					dis[v]=dis[u]+t[pd[u]][v]+t[pd[v]][v];
					q.push({dis[v],v,0});
				}
			}
		}
		else
		{
			for (int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if (dis[v]>dis[u])
				{
					if (more[v])
					{
						dis[v]=dis[u];
						q.push({dis[v],dis[u],1}); 
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,j;
	cin >> c >> n >> m >> d >> q;
	for (i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for (i=1;i<=n;i++)
	{
		cin >> k[i];
		int lst=0;
		for (j=1;j<=k[i];j++)
		{
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			if (!pd[a[i][j]])
			{
				pd[a[i][j]]=i;
			}
			else
			{
				more[a[i][j]]=1;
			}
			if (!lst)
			{
				lst=a[i][j];
			}
			else
			{
				g[a[i][j]].push_back(lst);
				g[lst].push_back(a[i][j]);
			}
		}
	}
	int x,y;
	while (q--)
	{
		for (int i=1;i<=m;i++)
		{
			dis[i]=1e9;
		}
		++tot;
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y]+t[pd[y]][y]+w[y] << '\n';
	}
	return 0;
}
