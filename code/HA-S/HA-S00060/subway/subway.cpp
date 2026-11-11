#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll c,n,m,d,q,T;
ll w[N],a[N],b[510][510];
struct node
{
	ll num,t;
};
vector<node> g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&T);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			b[i][j]=1e13;
		}
		b[i][i]=0;
	}
	for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++)
	{
		ll k,t,nd;
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++)
		{
			scanf("%lld%lld",&nd,&t);
			for(ll l=0;l<g[nd].size();l++)
			{
				ll v=g[nd][l].num,tt=g[nd][l].t;
				if(b[i][v]>t+tt)b[i][v]=b[v][i]=t+tt;
			}
			g[nd].push_back({i,t});
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<k;i++)
		{
			for(ll j=k+1;j<=n;j++)
			{
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
	}
	while(T--)
	{
		ll u,v,ans=1e13;
		scanf("%lld%lld",&u,&v);
		for(ll i=0;i<g[u].size();i++)
		{
			for(ll j=0;j<g[v].size();j++)
			{
				ll uu=min(g[u][i].num,g[v][j].num),vv=max(g[u][i].num,g[v][j].num);
				ans=min(ans,b[uu][vv]+g[u][i].t+g[v][j].t);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;	
}
