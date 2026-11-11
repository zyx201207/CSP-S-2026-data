#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll MAXN=505,MAXM=5e5+5,INF=1e16;
ll c,n,m,d,q,w[MAXM],dis[MAXN][MAXN];
struct node
{
	ll sbw,t;
	node(){}
	node(ll _sbw,ll _t){sbw=_sbw,t=_t;}
};
vector<node> st[MAXM];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i!=j) dis[i][j]=INF;
	for(ll i=1;i<=n;i++)
	{
		ll k;
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++)
		{
			ll a,t;
			scanf("%lld%lld",&a,&t);
			for(auto u:st[a])
			{
				dis[i][u.sbw]=min(dis[i][u.sbw],t+u.t);
				dis[u.sbw][i]=min(dis[u.sbw][i],t+u.t);
			}
			st[a].pb(node(i,t));
		}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(ll i=1;i<=n;i++)
//	{
//		for(ll j=1;j<=n;j++) cout<<setw(4)<<dis[i][j];
//		cout<<endl;
//	}
	while(q--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=INF;
		for(auto u:st[x])
			for(auto v:st[y])
				ans=min(ans,w[x]+u.t+dis[u.sbw][v.sbw]+v.t+w[y]);
		printf("%lld\n",ans);
	}
	return 0;
}
