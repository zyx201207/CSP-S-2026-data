#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

using uint = unsigned int;

int n, k;
vector<int> p[1000001];

bool prm[1000001];
int dist[1000001];

struct BFS
{
	int id, v;
};

int bfs()
{
	memset(dist, 0, sizeof(dist));
	queue<BFS> q;
	
	int res = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		if (prm[i]) q.push({i, 0});
	}
	
	while (!q.empty())
	{
		BFS x = q.front();
		q.pop();
		
		if (dist[x.id]) continue;
		dist[x.id] = x.v;
		res = max(res, x.v);
		
		for (uint i = 0; i < p[x.id].size(); ++i)
		{
			q.push({p[x.id][i], x.v + 1});
		}
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i < n; ++i)
		{
			int u, v;
			cin >> u >> v;
			
			p[u].push_back(v);
			p[v].push_back(u);
		}
		
		for (int i = 1; i <= k; ++i) prm[i] = 1;
		memset(prm + k + 1, 0, n - k);
		
		int res = 2147483647;
		do
		{
			res = min(res, bfs());
		}
		while (prev_permutation(prm + 1, prm + n + 1));
		
		cout << res << '\n';
	}
	
	return 0;
}
