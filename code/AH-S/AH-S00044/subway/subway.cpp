#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long w[N];
const int E=6e6+5;
int head[N],cnt;
struct node{
	int next,to;
	long long w;
}_g[E];
void insert(int x,int y,long long w)
{
	_g[++cnt].to=y;
	_g[cnt].next=head[x];
	head[x]=cnt;
	_g[cnt].w=w;
}
const int M=505;
long long g[M][M]; 
long long dis[M][M];
bool vis[M][M];
int c,n,m,d,q;
void dij(int ind)
{
	dis[ind][ind]=0;
	for(int i=1;i<=n;i++)
		dis[ind][i]=g[ind][i];
	for(int i=1;i<n;i++)
	{
		int mini=0;
		for(int j=1;j<=n;j++)
		{
			if(ind==j||vis[ind][j])continue;
			if(dis[ind][mini]>dis[ind][j])
				mini=j;
		}
		vis[ind][mini]=1;
		for(int j=1;j<=n;j++)
			if(dis[ind][mini]+g[mini][j]<dis[ind][j])
				dis[ind][j]=dis[ind][mini]+g[mini][j];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			int a;
			long long t;
			cin>>a>>t;
			insert(a,m+i,t);
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;++i)
	{
		for(int u=head[i];u;u=_g[u].next)
		{
			for(int v=head[i];v;v=_g[v].next)
			{
				int to1=_g[u].to-m,to2=_g[v].to-m;
				long long w1=_g[u].w,w2=_g[v].w;
				g[to1][to2]=g[to2][to1]=min(g[to1][to2],w1+w2);
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)
		g[i][i]=0;
	for(int i=1;i<=n;++i)
		dij(i);
	while(q--)
	{
		int x,y;
		long long ans=1e18;
		cin>>x>>y;
		for(int u=head[x];u;u=_g[u].next)
		{
			for(int v=head[y];v;v=_g[v].next)
			{
				int to1=_g[u].to-m,to2=_g[v].to-m;
				long long w1=_g[u].w,w2=_g[v].w;
				ans=min(ans,w1+w2+dis[to1][to2]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
