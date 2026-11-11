#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, d[2000001];
vector<int> g[2000001];
bool v[2000001];
priority_queue<int> q;
void dij(int x)
{
	
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	int u, v;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			d[u] = 0x7fffffff;
			d[v] = 0x7fffffff;
		}
		cout << abs(g[u][1]-g[v][1]) << '\n';
	}
	return 0;
}
