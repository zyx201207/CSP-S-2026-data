#include <bits/stdc++.h>
using namespace std;
#define int long long 
int ans[500005],dp[505],w[500005],nt[505],upd[500005];
struct Node 
{
	int x,nxt,t;
};
vector<pair<int,int>> qry[500005];
vector<Node> g[500005];
vector<pair<int,int>> g2[500005];
vector<Node> q2[500005]; 
bool f[500005];
const int inf = 1e18;
int c,n,m,d,q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int a,t;
			cin >> a >> t;
			g[a].push_back({i,-1,t});
			g2[i].push_back({a,t});
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int x,y;
		cin >> x >> y;
		if (x > y) swap(x,y);
		qry[x].push_back({i,y});
		ans[i] = inf;
	}
	for (int i = m;i >= 1;i--)
	{
		for (auto u : g[i]) 
		{
			if (nt[u.x] != -1) u.nxt = nt[u.x];
			nt[u.x] = i;
		}
	}
	for (int c = 1;c <= n;c++)
	{
		for (int i = 1;i <= n;i++) dp[i] = inf,upd[i] = 0;
		for (int i = 1;i <= m;i++) q2[i].clear();
		int j = -1;
		for (int i = 1;i <= m;i++)
		{
			if (j + 1 < (int)g2[c].size() && g2[c][j + 1].first == i) 
			{
				f[i] = 1;
				for (auto u : qry[i]) q2[u.second].push_back({u.first,i,g2[c][j + 1].second});
				j++;
			}
			else f[i] = 0;
		}
		queue<Node> Q;
		for (int i = 1;i <= m;i++)
		{
			int mi = inf;
			while (!Q.empty() && Q.front().x == i)
			{
				auto t = Q.front();
				Q.pop();
				dp[t.nxt] = t.t; 
				upd[t.nxt] = i;
			}
			for (auto u : g[i])
			{
				if (u.x == c) dp[c] = 0;
				if (upd[u.x] == i) mi = min(mi,dp[u.x] + u.t);
			}
			for (auto u : g[i])
			{
				dp[u.x] = min(dp[u.x],mi + u.t);
				mi = min(mi,dp[u.x] + u.t);
				if (dp[u.x] < inf && u.nxt != -1) Q.push({u.nxt,u.x,dp[u.x]});
			}
			for (auto u : q2[i])
			{
				int c = w[i] + w[u.nxt] + u.t + mi;
				ans[u.x] = min(ans[u.x],c);
			}
		}
	}
	for (int i = 1;i <= q;i++) cout << ans[i] << '\n';
	return 0;
}
