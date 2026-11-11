#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define vi vector<int>
#define i128 __int128
using namespace std;
const int maxn = 2e6 + 5;
const ll INF = 1e18;
int c, t, n;
ll d;
ll x[maxn];
vi g[maxn];
ll dis[maxn], cnt[maxn];
struct node
{
	int v;
	ll w;
	bool operator < (const node &b) const
	{
		return w > b.w;
	}
};
void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i], g[i].clear();
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(x[j] - x[i] <= d) g[i].emplace_back(j);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) dis[j] = INF, cnt[j] = 0;
		priority_queue<node>q;
		dis[i] = 0;
		cnt[i] = 1;
		q.push({i, 0});
		while(q.size())
		{
			auto tmp = q.top();
			q.pop();
			int u = tmp.v, w = tmp.w;
			if(w > dis[u]) continue;
			for(auto v: g[u])
			{
				if(dis[v] > dis[u] + 1) 
				{
					dis[v] = dis[u] + 1;
					cnt[v] = cnt[u];
					q.push({v, dis[v]});	
				}		
				else if(dis[v] == dis[u] + 1) cnt[v]++;
			}
		}
		for(int j = 1; j <= n; j++) if(cnt[j] == 2) ans++;
	} 
	cout << ans << '\n';
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
//(u,v)为双径岛屿对当且仅当只存在两个点 x,y，满足 dis(u,x) == dis(u,y) 且 dis(x,v) == dis(y,v), dis 指最短路 => x,y一定为相邻两点 
