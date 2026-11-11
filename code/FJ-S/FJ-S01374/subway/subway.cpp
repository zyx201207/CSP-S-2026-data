#include<bits/stdc++.h>
using namespace std;
struct cxk
{
	int nxt,to,val;
}edge[1000010];
int l_edge=0,head[5010],dis[5010][5010],w[5010],a[5010],t[5010],c,n,m,d,q;
bool vis[5010][5010],vx[5010];
void add_edge(int u,int v,int w)
{
	edge[++l_edge].val=w;
	edge[l_edge].to=v;
	edge[l_edge].nxt=head[u];
	head[u]=l_edge;
}
void dij(int s)
{
	vx[s]=1;
	queue<int>q;
	q.push(s);
	dis[s][s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[s][u])continue;
		vis[s][u]=1;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dis[s][v]<=dis[s][u]+edge[i].val)continue;
			dis[s][v]=dis[s][u]+edge[i].val;
			q.push(v);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(vx,0,sizeof(vx));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++)
			for(int z=1;z<j;z++)add_edge(a[j],a[z],t[j]+t[z]),add_edge(a[z],a[j],t[j]+t[z]);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(!vx[x])dij(x);
		if(!vx[y])dij(y);
		cout<<w[x]+w[y]+min(dis[x][y],dis[y][x])<<'\n';
	}
	return 0;
}
