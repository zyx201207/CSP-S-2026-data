#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k,w[500005],dis[505][505],ans,viss[505];
struct node
{
	int u,w;
};
vector<node> e[5005];
struct nod
{
	int id,w;
}a[1000005];
vector<nod> l[1000005];
vector<nod> vis[1000005];
bool cmp(nod x,nod y)
{
	return x.id<y.id;
}
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	dis[x][x]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(viss[u]) continue;
		viss[u]=1;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].u;
			if(dis[x][v]>dis[x][u]+e[u][i].w)
			{
				dis[x][v]=dis[x][u]+e[u][i].w;
				q.push(v);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin >>w[i];
	for(int i=1;i<=n;i++)
	{
		cin >>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin >>x>>y;
			vis[x].push_back(nod{i,j-1});
			l[i].push_back(nod{x,y});
		}
	}
	//cout <<1;
	for(int i=1;i<=m;i++)
	{
		if(vis[i].size()<2) continue;
		for(int j=0;j<vis[i].size();j++)
		{
			for(int o=0;o<vis[i].size();o++)
			{
				int u=vis[i][j].id,v=vis[i][o].id;
				if(u==v) continue;
				e[u].push_back(node{v,l[u][vis[i][j].w].w+l[v][vis[i][o].w].w});
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			cout <<e[i][j].u<<' '<<e[i][j].w<<endl;
		}
		cout <<endl;
	}
	*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		memset(viss,0,sizeof(viss));
	}
	while(q--)
	{
		ans=1e18;
		int xx,yy;
		cin >>xx>>yy;
		for(int i=0;i<vis[xx].size();i++)
		{
			for(int j=0;j<vis[yy].size();j++)
			{
				int u=vis[xx][i].id,v=vis[yy][j].id;
				//cout <<dis[u][v]<<endl;
				ans=min(ans,dis[u][v]+l[u][vis[xx][i].w].w+l[v][vis[yy][j].w].w+w[xx]+w[yy]);
			}
		 } 
		 cout <<ans<<'\n';
	}
	return 0;
}

