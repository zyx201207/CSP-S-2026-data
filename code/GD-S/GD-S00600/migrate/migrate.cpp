#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
ll c;
ll a[2000005];
ll vis[2000005];
vector<ll> g[2000005];
bool vis1[2000005];
ll n,m;
queue<ll> q;
ll p()
{
	ll ans = 0;
	while(!q.empty())
	{
		ll nt = q.size();
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= nt;i++)
		{
			ll x = q.front();
			q.pop();
			for(int i : g[x])
			{
				if(vis1[i])
				{
					continue;
				}
				q.push(i);
				vis[i]++;
			}
		}
		for(int i = 1;i <= n;i++)
		{
			if(vis[i] == 0)
			{
				continue;
			}
			vis1[i] = 1;
			if(vis[i] == 2)
			{
				ans++;
			}
			if(vis[i] >= 3)
			{
				for(int u : g[i])
				{
					vis1[u] = 1;
				} 
			}
		}
	}
	return ans;
}
void solve()
{
	
	for(int i=1;i <= 2000000;i++)
	{
		g[i].clear();
	}
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(c >=11 && c <= 12)
	{
		ll r = m/(a[2]-a[1]);
		r = r+r-1;
		cout << n-r << "\n";
		return;
	}
	if(c <= 10)
	{
		
		for(int i = 1;i <= n;i++)
		{
			ll cnt = 0;
			for(int j = i+1;j <= n;j++)
			{
				if((a[j]-a[i]) <= m)
				{
					g[i].push_back(j);
				}
				else
				{
					break;
				}
			}
		}
		ll ans = 0;
		for(int i =1;i <= n;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(vis1,0,sizeof(vis1));
			q.push(i);
			vis1[i] = 1;
			ans+=p();
		}
		cout << ans << "\n";
		return;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll t = 1;
	cin >> c;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
