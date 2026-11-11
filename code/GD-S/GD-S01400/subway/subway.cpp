#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll c,n,m,lo,q,d[500010],ans[100010],v[500010],w[500010],a[500010],b[500010];
struct node{ll st,ed,id;}qu[100010];
bool cmp(node a,node b){return a.st<b.st;}
vector<pll>G[500010];
void dij(ll st)
{
	priority_queue<pll,vector<pll>,greater<pll>>q;
	q.push({0,st});
	memset(d,0x3f3f3f3f,sizeof d);d[st]=0;
	memset(v,0,sizeof v);
	while(q.size())
	{
		ll x=q.top().second;q.pop();
		for(auto i:G[x])
		{
			ll y=i.first,w=i.second;
			if(d[y]>d[x]+w)
			{
				d[y]=d[x]+w;
				q.push({d[y],y});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&lo,&q);
	for(ll i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(ll i=1,x;i<=n;i++)
	{
		scanf("%lld",&x);
		for(ll j=1;j<=x;j++)scanf("%lld%lld",&a[j],&b[j]);
		for(ll j=1;j<x;j++)for(ll lp=j+1;lp<=x;lp++)
		{
			G[a[j]].emplace_back(a[lp],b[j]+b[lp]);
			G[a[lp]].emplace_back(a[j],b[j]+b[lp]);
		}
	}
	for(ll i=1;i<=q;i++)scanf("%lld%lld",&qu[i].st,&qu[i].ed),qu[i].id=i;
	sort(qu+1,qu+q+1,cmp);
	for(ll i=1;i<=q;i++)
	{
		if(qu[i].st!=qu[i-1].st)dij(qu[i].st);
		ans[qu[i].id]=w[qu[i].st]+w[qu[i].ed]+d[qu[i].ed];
	}
	for(ll i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}
