#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
struct wxjun
{
	ll v,w;	
	friend bool operator >(wxjun a,wxjun b)
	{
		return a.w>b.w;
	}
	friend bool operator <(wxjun a,wxjun b)
	{
		return a.w<b.w;
	}
};
void solve()
{
	ll TASK,n,m,D,q;
	cin>>TASK>>n>>m>>D>>q;
	vector<vector<wxjun>> E(m+1,vector<wxjun>(0));
	vector<ll> w(m+1,0);//口<->厅
	for(int i=1;i<=m;i++)
		cin>>w[i];
	vector<vector<ll>> t(n+1,vector<ll>(m+1,0))/*厅<->线*/,a(n+1,vector<ll>(0));//每条线的地铁口
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll x,y;
			cin>>x;a[i].push_back(x);
			cin>>y;t[i][x]=y;
		}
		for(int ui=0;ui<k-1;ui++)
		{
			for(int vi=ui+1;vi<k;vi++)
			{
				ll u=a[i][ui],v=a[i][vi];
				E[u].push_back({v,t[i][u]+t[i][v]});
				E[v].push_back({u,t[i][u]+t[i][v]});
			}
		}
	}
	while(q--)
	{
		ll u,v;
		cin>>u>>v;
		vector<ll> dis(m+1,1e18);
		vector<bool> vis(m+1,0);
		priority_queue<wxjun,vector<wxjun>,greater<wxjun>> q;
		q.push({u,0});
		dis[u]=0;
		while(!q.empty())
		{
			ll U=q.top().v;
			q.pop();
			if(vis[U])continue;
			for(auto V:E[U])
			{
				if(dis[V.v]>dis[U]+V.w)
				{
					dis[V.v]=dis[U]+V.w;
					q.push({V.v,dis[V.v]});
				}
			}
		}
		cout<<dis[v]+w[u]+w[v]<<endl;
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)solve();
	return 0;
}

