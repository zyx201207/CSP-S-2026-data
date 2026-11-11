#include<bits/stdc++.h>
#define ll long long
#define N 510
#define M 500500
using namespace std;

const ll INF=1e18;
const ll D=20;

struct edge
{
	ll to,next,w;
}e[M];

ll head[M],tot=0;

ll c,n,m,d,q;
ll w[M],k[N];
ll fl[M],tot_fl=0;
ll pa[M],pat[M],tot_pa=0;
ll dis[N][N];
bool mp[M];

void build(ll u,ll v,ll w)
{
	e[++tot]=(edge){v,head[u],w};
	head[u]=tot;
//	cout<<u<<" "<<v<<"\n";
}

void dfs(ll u)
{
	for(int i=head[u];i;i=e[i].next)
	{
		ll v=e[i].to;
//		cout<<u<<" "<<v<<"\n";
		pa[++tot_pa]=v;
		pat[tot_pa]=e[i].w;
	}
}

void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]!=INF && dis[k][j]!=INF)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=INF;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			ll a,t;
			cin>>a>>t;
			build(a,i,t);
			if(!mp[a])
			{
				mp[a]=true;
				fl[++tot_fl]=a;
			}
		}
	}
	for(int i=1;i<=tot_fl;i++)
	{
		tot_pa=0;
		for(int i=1;i<=d;i++) pa[i]=0;
		for(int i=1;i<=d;i++) pat[i]=0;
		dfs(fl[i]);
		for(int j=1;j<=tot_pa;j++)
		{
			for(int k=1;k<=tot_pa;k++)
			{
				if(j==k) continue;
				ll u=pa[j],v=pa[k];
				dis[u][v]=min(pat[j]+pat[k],dis[u][v]);
				dis[v][u]=min(pat[j]+pat[k],dis[v][u]);
			}
		}
	}
	floyd();
	while(q--)
	{
		ll x,y,ans=INF;
		cin>>x>>y;
		for(int i=head[x];i;i=e[i].next)
		{
			for(int j=head[y];j;j=e[j].next)
			{
				ll u=e[i].to,v=e[j].to;
				ans=min(ans,w[x]+w[y]+e[i].w+e[j].w+dis[u][v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
