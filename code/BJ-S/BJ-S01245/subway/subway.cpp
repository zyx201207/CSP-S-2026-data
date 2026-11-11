#include <bits/stdc++.h>
using namespace std;
const int N=8e4+5;
struct node{
	int v,line;
};
int c,n,m,d,q;
vector<node> adj[N];
int t[205][N];
int dis[N];
bool vis[N];
int linee[N];
void dj(int s)
{
	for (int i=1;i<=m;i++) dis[i]=2e9,vis[i]=0;
	queue<node> q;
	vis[s]=1;
	dis[s]=0;
	q.push({s,-1});
	while (q.size())
	{
		node cur=q.front();
		q.pop();
		if (vis[cur.v]) continue;
		vis[cur.v]=1;
		for (auto x:adj[cur.v])
		{
			int v=x.v,line=x.line;
			if (cur.line==-1)
			{
				if (dis[cur.v]+t[line][cur.v]<dis[v])
				{
					linee[v]=line;
					dis[v]=dis[cur.v]+t[line][cur.v];
				}
				q.push({v,line});
			}
			else if (cur.line!=line)
			{
				if (dis[v]>dis[cur.v]+t[cur.line][cur.v]+t[line][v])
				{
					dis[v]=dis[cur.v]+t[cur.line][cur.v]+t[line][v];
					linee[v]=line;
				}
				q.push({v,line});
			}
			else if (cur.line==line)
			{
				if (dis[cur.v]<dis[v])
				{
					dis[v]=dis[cur.v];
					linee[v]=line;
				}
				q.push({v,line});
			}
		}
	}
}
int w[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	if (n<=200)
	{
		for (int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			int u;
			cin>>u>>t[i][u];
			for (int j=2;j<=k;j++)
			{
				int v,w;
				cin>>v>>w;
				t[i][v]=w;
				adj[u].push_back({v,i});
			}
		}
		while (q--)
		{
			int x,y;
			cin>>x>>y;
			dj(x);
			cout<<dis[y]+w[x]+w[y]+t[linee[y]][y]<<"\n";
		}
	}
	return 0;
}
