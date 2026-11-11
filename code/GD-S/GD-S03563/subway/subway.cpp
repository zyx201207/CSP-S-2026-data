#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;

int w[500010], c, n, m, d, q;
int sta[500010];
vector<int> line[500010];
map<pair<int, int>, int> st;
struct node{int u, id, sum;};
int bfs(int s, int ed)
{
	map<pair<int, int>, bool> vis;
	queue<node> q;
	for(int i = 0; i < line[s].size(); i++)
	{
		int l = line[s][i];
		q.push({s, l, st[{s, l}]});
	}
	int res = 1e18;
	while(!q.empty())
	{
		int u = q.front().u, id = q.front().id, sum = q.front().sum;
		q.pop();
		if(u == ed)
		{
			res = min(res, sum + st[{ed, id}]);
			continue;
		}
		if(vis[{u, id}]) continue;
		vis[{u, id}] = 1;
		for(int v = 1; v <= m; v++)
		{
			if(st[{v, id}] > 0)
			{
				q.push({v, id, sum});
				for(int j = 0; j < line[v].size(); j++)
				{
					int l = line[v][j];
					if(l == id) continue;
					int cost = st[{v, id}] + st[{v, l}];
					q.push({v, l, sum + cost});
				}
			}
		}
	}
	return res;
}
void solve()
{
	int start, end;
	cin >> start >> end;
	int ans = w[start] + w[end];
	int sum = bfs(start, end);
	cout << ans + sum << endl;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int t;
			cin >> sta[j] >> t;
			line[sta[j]].push_back(i);
			st[{sta[j], i}] = t;
		}
	}
	while(q--) solve();
	return 0;
}
