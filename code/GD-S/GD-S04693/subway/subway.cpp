#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define int long long
int c,n,m,d,q,a[500005],k[500005],dis[5005][5005];
bool vis[500005];
struct node
{
	int v,w;
};
vector<node> e1[500005],e2[500005];
void dij(int x)
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m;i++)
		dis[x][i]=1e18;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,x});
	dis[x][x]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e1[u].size();i++)
		{
			int v=e1[u][i].v,w=e1[u][i].w;
			for(int j=0;j<e2[v].size();j++)
			{
				int vv=e2[v][j].v,ww=e2[v][j].w;
				if(vv==u)continue;
				if(dis[x][vv]>dis[x][u]+ww+w)
				{
					dis[x][vv]=dis[x][u]+w+ww;
					q.push({dis[x][vv],vv});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int v,w;
			cin>>v>>w;
			e2[i+m].push_back({v,w});
			e1[v].push_back({i+m,w});
		}
	}
	for(int i=1;i<=m;i++)
		dij(i);
	/*for(int i=1;i<=m;i++)
	{
		cout<<i<<"\n";
		for(int j=0;j<e1[i].size();j++)
			cout<<e1[i][j].v<<" ";
		cout<<"\n";
	}
	for(int i=1;i<=m+n;i++)
	{
		for(int j=i+1;j<=m+n;j++)
		{
			cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
		}
	}*/
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+a[u]+a[v]<<"\n";
	}
	return 0;
}
