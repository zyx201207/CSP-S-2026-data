#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const ll N = 5e5+510;
ll c,n,m,d,q,a[N],dis[N];
bool vis[N];
struct node{
	ll v,w; 
};
struct node1{
	ll value,num;
	bool operator < (const node1&a) const{return num > a.num;} 
};
vector<node> G[N];
priority_queue<node1> p;
void dijskra(ll u,ll v)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis)); 
	p.push({0,u});
	dis[u] = 0;
	while(!p.empty())
	{
		ll t = p.top().num;
		vis[t] = 1;
		p.pop();
		for(int i = 0;i < G[t].size();i++)
		{
			ll v = G[t][i].v;
			dis[v] = min(dis[t]+G[t][i].w,dis[v]);
			if(!vis[v]) p.push({dis[v],v});
		}
	}
	cout<<dis[v]+a[u]+a[v]<<endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++)
	{
		ll k,vv,t;
		cin>>k;
		for(int j = 1;j <= k;j++)
		{
			cin>>vv>>t;
			G[m+i].push_back({vv,t});
			G[vv].push_back({m+i,t});
		}
	}
	for(int i = 1;i <= q;i++)
	{
		ll x,y;
		cin>>x>>y;
		dijskra(x,y);
	}
	return 0;
}
