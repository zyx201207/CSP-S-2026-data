#include<bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
using namespace std;
const int N=1e6+5;
ll c,n,m,dic,q;
ll wz[N];
ll k[N];
ll a[N],t[N];
vector<pp>g[N];
ll vis[N];
ll d[N];
ll maxx;
void dij(ll st)
{
	for(int i=1;i<=m;i++)
	{
		d[i]=INT_MAX; 
		vis[i]=0;
	}
	d[st]=0;
	priority_queue<pp,vector<pp>,greater<pp>>q;
	q.push({0,st});
	while(!q.empty())
	{
		ll u=q.top().second;
		q.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			ll v=g[u][i].first,w=g[u][i].second;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>dic>>q;
	for(int i=1;i<=m;i++)cin>>wz[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
			//g[a].push_back({i,t});//线路，时间 
		}
		maxx=max(maxx,k[i]);
		for(int j=1;j<=k[i];j++)
		{
			for(int z=1;z<=k[i];z++)
			{
				g[a[j]].push_back({a[z],t[j]+t[z]});
				g[a[z]].push_back({a[j],t[z]+t[j]});
			}
		}
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		if(x==y)
		{
			cout<<0;
			continue;
		}
		dij(x);
		cout<<wz[x]+d[y]+wz[y]<<"\n";
	}
	return 0;
}

