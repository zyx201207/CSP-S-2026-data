#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=600005;
ll c,n,m,d,as,w[N],k;
ll head[N],nxt[N*22],to[N*22],val[N*22],cnt;
ll dis[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
void add(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
	val[cnt]=z;
}
ll query(ll x,ll y)
{
	for(int i=0;i<=m+n+1;i++)dis[i]=1e16;
	dis[x]=0;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(dis[u.second]!=u.first)continue;
		for(int i=head[u.second];i;i=nxt[i])
		{
			int v=to[i],vl=val[i];
			if(dis[v]>dis[u.second]+vl)
			{
				dis[v]=dis[u.second]+vl;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	return w[x]+w[y]+dis[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>as;
	for(ll i=1;i<=m;i++)cin>>w[i];
	ll x,y;
	for(ll i=1;i<=n;i++)
	{
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			cin>>x>>y;
			add(m+i,x,y);add(x,m+i,y);
		}
	}
	while(as--)
	{
		cin>>x>>y;
		cout<<query(x,y)<<'\n';
	}
	return 0;
}
