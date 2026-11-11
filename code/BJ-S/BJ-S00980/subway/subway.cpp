#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int c, n, m, d, q, a[N];
long long w[N], t[N][505], ans;

struct edge
{
	int to;
	long long wgt;
};
vector<edge> G[N];

bool vis[N];
void DFS(int u, int end, long long sum)
{
	if (u == end) { ans = sum; return; }
	
	vis[u] = true;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int v = G[u][i].to;
		long long wgt = G[u][i].wgt;
		if (!vis[v] && !ans)
		{
			DFS(v, end, sum + wgt);
			vis[v] = false;
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];

	for (int i = 1, k; i <= n; i++)
	{
	    cin >> k;
	    for (int j = 1; j <= k; j++) cin >> a[j] >> t[j][i];
	    
	    for (int j = 1; j < k; j++)
	    {
			int u = a[j], v = a[j + 1];
			long long wgt = t[u][i] + t[v][i];
			
			G[u].push_back({ v, wgt });
			G[v].push_back({ u, wgt });
		}
	}

	int x, y;
	while (q--)
    {
		cin >> x >> y;
		ans = 0; DFS(x, y, 0);
		cout << ans + w[x] + w[y] << "\n";
    }

	return 0;
}