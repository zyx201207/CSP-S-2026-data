#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
vector<pair<ll,ll> > a[600001];
ll di[500001];
ll dis[501][501];
ll c,n,m,d,q;
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > qu;
void dijs(ll st)
{
	for (ll i=1;i<=n;i++)dis[st][i]=1e18;
	while (qu.size())qu.pop();
	dis[st][st]=0;
	qu.push(make_pair(0,st));
	while (qu.size())
	{
		ll x=qu.top().second,dd=qu.top().first;
//		if (st==1)cout<<x<<'\n';
		qu.pop();
		if (dd>dis[st][x])continue;
		for (ll i=0;i<a[x].size();i++)
		{
			ll y=a[x][i].first;
			ll z=a[x][i].second;
//			if (st==1)cout<<dis[st][y]<<' '<<dis[st][x]<<' '<<z<<'\n';
			if (dis[st][y]>dis[st][x]+z)
			{
				dis[st][y]=dis[st][x]+z;
				qu.push(make_pair(dis[st][y],y));
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (ll i=1;i<=m;i++)cin>>di[i];
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=n;j++)dis[i][j]=1e18;
		ll k;
		cin>>k;
		for (ll j=1;j<=k;j++)
		{
			ll x,t;
			cin>>x>>t;
			a[x+n].push_back(make_pair(i,t));
		}
	}
	for (ll i=1;i<=m;i++)
	{
		ll x=i+n;
		for (ll j=0;j<a[x].size();j++)
		{
			for (ll k=j+1;k<a[x].size();k++)
			{
				ll u=a[x][j].first,v=a[x][k].first,w=a[x][j].second,z=a[x][k].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w+z);
			}
		}
	}
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=n;j++)
		{
			if (dis[i][j]!=1e18)
			{
				a[i].push_back(make_pair(j,dis[i][j]));
//				cout<<i<<"->"<<j<<':'<<dis[i][j]<<'\n';
			}
		}
	}
	for (ll i=1;i<=n;i++)
	{
		dijs(i);
//		for (ll j=1;j<=n;j++)cout<<dis[i][j]<<' ';
//		cout<<'\n';
	}
	while (q--)
	{
		ll s,t;
		cin>>s>>t;
		s+=n;t+=n;
		ll ans=1e18;
		for (ll j=0;j<a[s].size();j++)
		{
			for (ll k=0;k<a[t].size();k++)
			{
				ll u=a[s][j].first,v=a[t][k].first,w=a[s][j].second,z=a[t][k].second;
				ans=min(ans,dis[u][v]+w+z);
//				cout<<u<<' '<<v<<' '<<dis[u][v]<<'\n';
			}
		}
		cout<<ans+di[s-n]+di[t-n]<<'\n';
	}
	return 0;
}

