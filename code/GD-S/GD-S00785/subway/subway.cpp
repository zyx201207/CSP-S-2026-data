#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
typedef long long ll;
using namespace std;

struct node
{
	int u;
	ll dis;
	bool operator< (const node &rhs) const
	{
		return dis > rhs.dis;
	}
};
int totnodes, c, n, m, d, q, etex[500005], k[505], mainroom[500005], queries[500005][2], lines[500005];
bool need[500005];
ll dist[500005];
vector<int> a[505], t[505], g[500005], cost[500005];

ll dijkstra(int start_node, int end_node)
{
	memset(dist, 0x3f, sizeof(dist));
	dist[start_node] = 0;
	priority_queue<node> q;
	q.push({start_node, 0});
	ll ans = 0;
	while (!q.empty())
	{
		int u = q.top().u;
		q.pop();
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			if (dist[v] != 0x3f3f3f3f3f3f3f3f) continue;
			dist[v] = dist[u] + cost[u][i];
			q.push({v, dist[v]});
		}
	}
	return dist[end_node];
}



int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> etex[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int aa, tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			lines[aa]++;
			if (lines[aa] == 2) need[aa] = true;
		}
	}
	
	for (int i = 1; i <= q; i++)
	{
		int start_node, end_node;
		cin >> start_node >> end_node;
		queries[i][0] = start_node;
		queries[i][1] = end_node;
		need[start_node] = need[end_node] = true;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int last_need = 0;
		for (int j = 0; j < k[i]; j++)
		{
			if (need[a[i][j]])
			{
				totnodes++;
				if (last_need)
				{
					g[totnodes].push_back(last_need);
					g[last_need].push_back(totnodes);
					cost[totnodes].push_back(0);
					cost[last_need].push_back(0);
				}
				last_need = totnodes;
				if (!mainroom[a[i][j]])
				{
					mainroom[a[i][j]] = totnodes + 1;
					g[totnodes].push_back(mainroom[a[i][j]]);
					g[mainroom[a[i][j]]].push_back(totnodes);
					cost[totnodes].push_back(t[i][j]);
					cost[mainroom[a[i][j]]].push_back(t[i][j]);
					totnodes++;
				}
				else
				{
					g[totnodes].push_back(mainroom[a[i][j]]);
					g[mainroom[a[i][j]]].push_back(totnodes);
					cost[totnodes].push_back(t[i][j]);
					cost[mainroom[a[i][j]]].push_back(t[i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= q; i++)
	{
		ll output = etex[queries[i][0]] + etex[queries[i][1]] + dijkstra(mainroom[queries[i][0]], mainroom[queries[i][1]]);
		cout << output << endl;
	}
	return 0;
}
