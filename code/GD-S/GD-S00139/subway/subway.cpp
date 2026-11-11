#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXM 500005
#define MAXN 502
#define inf 0x3f3f3f3f3f3f3f3f
ll n,m,d,q;
ll w[MAXM],a[MAXM];
struct node{
	ll v,w;
	node(){}
	node(ll V,ll W):v(V),w(W) {} 
};
vector<node> g[MAXM+MAXN];
ll dis[MAXN+MAXM];
struct hp
{
	ll v,dis;
	hp(){}	
	hp(ll V, ll DIS):v(V), dis(DIS) {} 
};
struct cmp{
	bool operator() (hp x, hp y)
	{
		return x.dis>y.dis;
	}
};
priority_queue<hp,vector<hp>,cmp> h;
ll dijkstra(ll x, ll y)
{
	while(!h.empty())h.pop();
	for(ll i=0;i<=m+n;i++)dis[i]=inf;
	dis[x]=0;
	h.push(hp(x,0));
	while(!h.empty())
	{
		hp top=h.top();
		h.pop();
		if(dis[top.v]<top.dis) continue;
		for(node j:g[top.v])
		{
			if(dis[j.v]>top.dis+j.w)
			{
				dis[j.v]=top.dis+j.w;
				h.push(hp(j.v,dis[j.v]));
			}
		}
	}
	return dis[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll c;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll x,y;
			cin>>x>>y;
			g[x].push_back(node(m+i,y));
			g[m+i].push_back(node(x,y));
		}
	}
	
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)+w[x]+w[y]<<endl;
	}
	
	
	return 0;
}
