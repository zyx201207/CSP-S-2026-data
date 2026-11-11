#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct node
{
	int x, y, d;
}a[N];
int c, t, sid[N], n, k, ce, b[N];
vector <int> ve[N];
void bfs(int u)
{
	int cnt = 1;
	b[u] = 1;
	priority_queue <pair <int, int> > q;
	vector <int> v;
	q.push({u, sid[u]});
	while(cnt <= k)
	{
		ce ++;
		while(!q.empty())
		{
			int x = q.top().first;
			q.pop();
			for(int i = 0; i < (int)ve[x].size(); i ++)
			{
				int y = ve[x][i];
				if(b[y] == 1) continue;
				b[y] = 1;
				v.push_back(y);
				cnt ++;
			}
		}
		for(int i = 0; i < (int)v.size(); i ++)
		{
			q.push({v[i], sid[v[i]]});
		}
	}
}
void solve()
{
	cin >> n >> k;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
		sid[u] ++;
		sid[v] ++;
	}
	int idx = 0, maxn = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(sid[i] > maxn)
		{
			idx = i;
			maxn = sid[i];
		}
	}
	bfs(idx);
	int ans = ce;
	ce = 0;
	int id = 0, maxnn = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(sid[i] > maxnn)
		{
			id = i;
			maxnn = sid[i];
		}
	}
	bfs(id);
	cout << ans + ce << "\n";
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}

