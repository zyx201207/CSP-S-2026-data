#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[50005],dis[505][505],vis[50005],idx;
vector<int> g[500005],t[500005],G[500005],T[500005];
struct node
{
	int pos,d;
};
bool operator<(node x,node y)
{
	return x.d>y.d;
}
priority_queue<node> Q;
void dij(int s)
{
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	Q.push({s,0});
	while(!Q.empty())
	{
		int x=Q.top().pos;
		Q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for (int i=0;i<g[x].size();i++)
			if(dis[s][g[x][i]]>dis[s][x]+t[x][i])
			{
				dis[s][g[x][i]]=dis[s][x]+t[x][i];
				if(!vis[g[x][i]])
					Q.push({g[x][i],dis[s][g[x][i]]});
			}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		int k,x,y;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>x>>y;
			G[x].push_back(i);
			T[x].push_back(y);
		}
	}
	for (int i=1;i<=m;i++)
		for (int j=0;j<G[i].size();j++)
			for (int k=0;k<G[i].size();k++)
				if(k!=j)
					g[G[i][j]].push_back(G[i][k]),t[G[i][j]].push_back(T[i][j]+T[i][k]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dis[i][j]=1e18;
	for (int i=1;i<=n;i++)
		dij(i);
	while(q--)
	{
		int x,y,ans=1e18;
		cin>>x>>y;
		for (int i=0;i<G[x].size();i++)
			for (int j=0;j<G[y].size();j++)
				ans=min(ans,T[x][i]+T[y][j]+dis[G[x][i]][G[y][j]]);
		swap(x,y);
		for (int i=0;i<G[x].size();i++)
			for (int j=0;j<G[y].size();j++)
				ans=min(ans,T[x][i]+T[y][j]+dis[G[x][i]][G[y][j]]);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
