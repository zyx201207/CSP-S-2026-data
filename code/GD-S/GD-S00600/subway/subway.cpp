#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
struct p1
{
	ll v,w;
};
ll w[500005];
ll a[500005];
ll t[500005];
bool cmp(p1 x,p1 y)
{
	return x.w < y.w;
}
vector<p1> g[500005];
ll ans = 1e18;

void p(ll x,ll lo,ll r,ll fa)
{
	if(x == r)
	{
		ans = min(ans,lo);
		return;
	}
	for(auto i : g[x])
	{
		if(i.v == fa)
		{
			continue;
		}
		p(i.v,lo+i.w,r,x);
	}
}
void solve()
{
	ll c;
	cin >> c;
	ll n,m,d,q;
	cin >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	
	if(c >= 7 && c <= 11)
	{
		for(int i = 1;i <= n;i++)
		{
			ll k;
			cin >> k;
			ll u,x,v,y;
			cin >> u >> x>> v >> y;
			x+=y;
			g[u].push_back({v,x});
			g[v].push_back({u,x});
			
			
		}
		
		for(int i =1;i <= q;i++)
		{
			ll u,v;
			cin >> u >> v;
			p(u,0,v,0);
			cout << ans+w[u]+w[v] << "\n";
		}
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		ll k;
		cin >> k;
		for(int i = 1;i <= k;i++)
		{
			cin >> a[i] >> t[i];
		}
		for(int i = 1;i <= k;i++)
		{
			for(int j = i+1;j <= k;j++)
			{
				ll u =a[i];
				ll v = a[j];
				g[u].push_back({v,t[i]+t[j]});
				g[v].push_back({u,t[i]+t[j]});
			}
		}
	}
	for(int i =1;i <= q;i++)
	{
		ll u,v;
		cin >> u >> v;
		p(u,0,v,0);
		cout << ans+w[u]+w[v] << "\n";
	}
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll t =1;
//	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
