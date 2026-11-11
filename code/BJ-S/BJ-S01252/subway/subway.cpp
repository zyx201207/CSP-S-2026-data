#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=507;
const ll M=5e5+7;
ll c,n,m,d,q;
ll w[M];
ll k[N];
vector<ll> f[M];
struct edge
{
	ll v,t;
};
struct node
{
	ll u,d;
};
vector<edge> G[N];
bool cmp(node x,node y)
{
	return x.d>y.d;
}
ll dis[N];
map<ll,ll> tt[N];
ll calc(ll x,ll y)
{
	priority_queue<node,vector<node>,decltype(cmp)* > q(cmp);
	q.push((node){x,0});
	dis[x]=0;
	while(!q.empty())
	{
		ll u=q.top().u;
		q.pop();
		ll len=G[u].size();
		for(ll i=0;i<len;i++)
		{
			ll v=G[u][i].v,t=G[u][i].t;
			if(dis[u]+t<dis[v])
			{
				dis[v]=dis[u]+t;
				q.push((node){v,dis[v]});
			}
		}	
	}
	return dis[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)
		{
			ll a,t;
			cin>>a>>t;
			tt[i][a]=t;
			if(f[a].size())
			{
				ll len=f[a].size();
				for(ll id=0;id<len;id++)
				{
					ll j=f[a][id];
					G[i].push_back((edge){j,tt[j][a]+t});
					G[j].push_back((edge){i,tt[j][a]+t});
				}
			}
			f[a].push_back(i);
		}
	}
	while(q--)
	{
		ll x,y,ans=0;
		cin>>x>>y;
		ans=LONG_LONG_MAX;
		ll len1=f[x].size(),len2=f[y].size();
		for(ll i=0;i<len1;i++)
		{
			for(ll j=0;j<len2;j++)
			{
				if(f[x][i]==f[y][j])
				{
					ans=min(ans,w[x]+w[y]+tt[f[x][i]][x]+tt[f[y][j]][y]);
					continue;
				}
				for(ll k=1;k<=m;k++)
				{
					dis[k]=M+7;
				}
				ans=min(ans,w[x]+w[y]+tt[f[x][i]][x]+tt[f[y][j]][y]+calc(f[x][i],f[y][j]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
