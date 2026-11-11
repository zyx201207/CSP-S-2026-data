#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2e6 + 5;
typedef long long ll;
int n;
ll d;
ll a[MAXN];
vector<ll> g[MAXN];
int dij[MAXN], tot[MAXN];
void bfs(int x)
{
	for (int i = 1; i <= n; i++)
	{
		dij[i] = 0x7fffffff;
		tot[i] = 0;
	}
	dij[x] = 0;
	tot[x] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto ed : g[u])
		{
			int v = ed;
			if (dij[u] + 1 > dij[v])
			{
				continue;
			}
			if (dij[u] + 1 == dij[v])
			{
				tot[v]++;
				q.push(v);
			}
			if (dij[u] + 1 < dij[v])
			{
				dij[v] = dij[u] + 1;
				tot[v] = 1;
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			g[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (a[j] - a[i] > d)
					break;
				g[i].push_back(j);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			bfs(i);
			for (int j = i + 1; j <= n; j++)
			{
				if (tot[j] == 2)
					ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/**
byebye 
my last csp-s
and may be my
last oi-competetion
18:27
*/
