#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e6 + 50;
ll c, t, ans = 0, x[N], dp[N];
vector<ll> G[N];
queue<ll> q;
bool vis[N];

bool check(ll s, ll t)
{
	dp[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		ll u = q.front();
		q.pop();
		if(u == t)
		{
			if(dp[u] == 2) return 1;
			else return 0;
		}
		for(ll v : G[u])
		{
			if(vis[v]) continue;
			dp[v] = dp[u] + 1;
			q.push(v);
			vis[v] = 1;
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		ans = 0;
		ll n = 0, d = 0;
		cin >> n >> d;
		for(ll i = 1; i <= n; i++) cin >> x[i];
		for(ll i = 0; i <= n; i++) G[i].clear();
		for(ll i = 1; i <= n; i++)
		{
			for(ll j = i + 1; j <= n; j++)
			{
				if(x[j] - x[i] <= d) G[i].push_back(j);
			}
		}
		for(ll u = 1; u <= n; u++)
		{
			for(ll v = u + 1; v <= n; v++)
			{
				// 一定记得清空!
				memset(dp, 0, sizeof(dp));
				memset(vis, 0, sizeof(vis)); 
				if(check(u, v)) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;	
}
