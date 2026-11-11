#include<bits/stdc++.h>
#define ll long long 
#define ygkg putchar(' ')
#define endl putchar('\n')
#define fi first
#define se second
const ll mod=998244353;
const ll inf=1e16;
namespace io
{
	template<typename L>
	void in(L &x)
	{
		x=0;bool p=0;char ch=getchar();
		while(!isdigit(ch)) p=ch=='-',ch=getchar();
		do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(isdigit(ch));
		x=p?-x:x;
	}
	template<typename L>
	void _out(L x){if(x) _out(x/10),putchar((x%10)^48);}
	template<typename L>
	void out(L x){_out(x>0?x:(x?(putchar('-'),-x):(putchar('0'),0))),endl;}	
}
using namespace io;
using namespace std;
ll c,n,m,d,q;
ll w[500015];
vector<pair<ll,ll>> e[500015];
ll dis[515][515];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	in(c),in(n),in(m),in(d),in(q);
	for(ll i=1;i<=m;++i) in(w[i]);
	for(ll i=1;i<=n;++i)
	{
		ll k;in(k);
		for(ll j=1;j<=k;++j)
		{
			ll a,t;in(a),in(t);
			e[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j) dis[i][j]=inf;
	for(ll i=1;i<=n;++i) dis[i][i]=0;
	for(ll i=1;i<=m;++i)
	{
		ll lim=e[i].size();
		for(ll j=0;j<lim;++j)
			for(ll k=j+1;k<lim;++k)
			{
				ll u=e[i][j].fi,v=e[i][k].fi;
				dis[u][v]=min(dis[u][v],e[i][j].se+e[i][k].se);
			}
	}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			dis[i][j]=dis[j][i]=min(dis[i][j],dis[j][i]);
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			for(ll k=1;k<=n;++k)
				if(dis[j][i]+dis[i][k]<dis[j][k])
					dis[j][k]=dis[j][i]+dis[i][k];
//	for(ll i=1;i<=n;++i)
//	{
//		for(ll j=1;j<=n;++j) cout<<dis[i][j]<<" ";
//		endl;
//	}
	while(q--)
	{
		ll u,v;in(u),in(v);
		ll ans=inf;
		for(auto p:e[u])
			for(auto q:e[v])
				ans=min(ans,dis[p.fi][q.fi]+p.se+q.se);
		out(ans+w[u]+w[v]);
	}
	return 0;
}
