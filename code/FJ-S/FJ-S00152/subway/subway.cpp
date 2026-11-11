#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[510][510];
vector<int> station[500010];
vector<pair<int,int>> g[510];
int t[500010][510];
int w[500010];

void dijstra(int s)
{
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	f[s][s] = 0;
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		for (auto i : g[u])
		{
			int v = i.first,w = i.second;
			if (f[s][v] > f[s][u] + w)
			{
				f[s][v] = f[s][u] + w;
				q.push({-f[s][v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,d,q,c;
	cin >> c >> n >> m >> d >> q;
	memset(f,0x3f,sizeof f);
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++) f[i][i] = 0;
	for (int i = 1;i <= n;i++)
	{
		int l;
		cin >> l;
		for (int j = 1;j <= l;j++)
		{
			int x;
			cin >> x;
			cin >> t[x][i];
			for (int k : station[x])
			{
				g[k].push_back({i,t[x][k] + t[x][i]});
				g[i].push_back({k,t[x][k] + t[x][i]});
			}
			station[x].push_back(i);
		}
	}
	for (int i = 1;i <= n;i++) dijstra(i);
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		ll ans = 1e18;
		for (int i : station[x])
		{
			for (int j : station[y])
			{
				ans = min(ans,t[x][i] + f[i][j] + t[y][j]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
