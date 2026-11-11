#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=503,M=5e5+3;
const ll INF=1e17; 
int c,n,m,d,q,h[N],cnt;
ll w[M],ds[N][N],dis[N];
bool vis[N];
int ln[M];
struct Node
{
	int pos;ll val;
}a[M][23];
struct Edge
{
	int nxt,to;ll val;
}e[M<<1];
void add(int u,int v,ll w)
{
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	e[cnt].val=w;
	h[u]=cnt;
}
void dij(int st)
{
	for(int i=0;i<=n;i++)
		dis[i]=INF,vis[i]=0;
	dis[st]=0;
	for(int i=1;i<=n;i++)
	{
		int u=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]<dis[u]) u=j;
		if(!u) break;
		vis[u]=1;
		for(int j=h[u];j;j=e[j].nxt)
		{
			int v=e[j].to;
			dis[v]=min(dis[v],dis[u]+e[j].val);
		}
	}
	for(int i=1;i<=n;i++)
		ds[st][i]=dis[i];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			int y;ll z;
			scanf("%d%lld",&y,&z);
			a[y][++ln[y]]={i,z};
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=ln[i];j++)
		{
			for(int k=j+1;k<=ln[i];k++)
			{
				int x=a[i][j].pos,y=a[i][k].pos;
				ll v=a[i][j].val+a[i][k].val;
				add(x,y,v),add(y,x,v);
//				printf("  %d %d   %lld\n",x,y,v);
			}
		}
//		printf("i=%d\n",i);
//		for(int j=1;j<=ln[i];j++)
//			printf("  %d %lld\n",a[i][j].pos,a[i][j].val);
	}
	for(int i=1;i<=n;i++)
		dij(i);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			printf("%d %d    %lld\n",i,j,ds[i][j]);
//	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=INF;
		for(int i=1;i<=ln[x];i++)
		{
			for(int j=1;j<=ln[y];j++)
			{
				int u=a[x][i].pos,v=a[y][j].pos;
				if(ds[u][v]==INF) continue;
				ans=min(ans,w[x]+w[y]+a[x][i].val+a[y][j].val+ds[u][v]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
