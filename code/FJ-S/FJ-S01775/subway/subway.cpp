#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll INF=1e18;
const int N=500+10;

int c,n,m,d,q;
int len[N];
struct node{
	int v;
	ll w;
};
vector<node>a[500010];
ll b[500010];
ll dis[N][N];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%lld",&b[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&len[i]);
		int now;
		ll num;
		for(int j=1;j<=len[i];++j)
		{
			scanf("%d%lld",&now,&num);
			a[now].push_back({i,num}); 
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<a[i].size();++j)
		{
			for(int k=0;k<a[i].size();++k)
			{
				int s=a[i][j].v;
				int t=a[i][k].v;
				dis[s][t]=min(dis[s][t],a[i][j].w+a[i][k].w);
			}
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ll ans=INF;
		for(int i=0;i<a[u].size();++i)
		{
			for(int j=0;j<a[v].size();++j)
			{
				int s=a[u][i].v;
				int t=a[v][j].v;
				ans=min(ans,dis[s][t]+a[u][i].w+a[v][j].w);
			}
		}
		printf("%lld\n",b[u]+b[v]+ans);
	}
}

