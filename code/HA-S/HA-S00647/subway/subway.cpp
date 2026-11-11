#include<bits/stdc++.h>
using namespace std;
typedef long long ll;		
constexpr int N=505+5,M=5e5+5;
constexpr ll INF=1e18;
int c=0,n=0,m=0,d=0,q=0;
ll w[M]={},e[N][N]={};
struct node
{
	int v;
	ll w;
};
vector<node> zt[M];
void floyd()
{
	int i=0,j=0,k=0;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
}
int main()
{
	freopen("subway.in","r",stdin);					//is not 3
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll i=0,j=0,a=0,t=0,k=0,u=0,v=0,dis=0,x=0,y=0;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				e[i][j]=INF;
	for(i=1;i<=m;i++)
		cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>a>>t;
			zt[a].push_back({i,t});
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=0;j<zt[i].size();j++)
			for(k=j+1;k<zt[i].size();k++)
			{
				u=zt[i][j].v,v=zt[i][k].v;
				e[u][v]=min(e[u][v],zt[i][j].w+zt[i][k].w);
				e[v][u]=min(e[v][u],zt[i][j].w+zt[i][k].w);	
			}
	}
	floyd();
	for(i=1;i<=q;i++)
	{
		cin>>u>>v;
		dis=INF;
		for(j=0;j<zt[u].size();j++)
			for(k=0;k<zt[v].size();k++)
			{
				x=zt[u][j].v,y=zt[v][k].v;
				dis=min(dis,e[x][y]+zt[u][j].w+zt[v][k].w);
			}
		cout<<dis+w[u]+w[v]<<'\n';
	}
	return 0;
}
