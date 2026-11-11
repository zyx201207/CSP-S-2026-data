#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],t[501][500001];
bool vis[500001];
vector<pair<int,int>>a[500001];
struct node
{
	int x,t;	
};
int bfs(int xr,int yr)
{
	queue<node>q;
	q.push({xr,w[xr]+w[yr]});
	while (!q.empty())
	{
		int xx=q.front().x;
		int tt=q.front().t;
		q.pop();
		if (xx==yr)
			return tt;
		vis[xx]=true;	
		for (pair<int,int> e:a[xx])
			if (!vis[e.first])
				q.push({e.first,tt+t[e.second][xx]+t[e.second][e.first]});
	}	
	return -1;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for (int i=1,p,u,v;i<=n;i++)
	{
		scanf("%d%d",&p,&u);
		scanf("%d",&t[i][u]);
		for (int j=2;j<=p;j++)
		{
			scanf("%d",&v);
			scanf("%d",&t[i][v]);
			a[u].push_back({v,i});	
			a[v].push_back({u,i});
		}
	}
	while (q--)
	{
		int xr,yr;
		scanf("%d%d",&xr,&yr);
		printf("%d\n",bfs(xr,yr));
		memset(vis,false,sizeof vis);
	}
}
