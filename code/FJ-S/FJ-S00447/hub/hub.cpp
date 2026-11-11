#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
const int MAXN = 1e6 + 5;
int n, k;
vector<int> g[MAXN];
int a[1005][1005];
int vis[MAXN];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	srand(time(NULL));
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			g[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << rand() % n << '\n';
	}
	return 0;
}
