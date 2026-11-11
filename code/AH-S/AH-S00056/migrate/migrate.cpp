#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int x[N];
vector<int> times;
int n, d;
void dfs(int pos, int v, int fly)
{
	if (pos > v) return;
	if (pos == v)
	{
		times.push_back(fly);
		return;
	}
	for (int i = pos + 1; i <= v; i++)
	{
		if (x[i] - x[pos] <= d) dfs(i, v, fly + 1);
		else break;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int u = 1; u <= n; u++)
		{
			for (int v = u + 1; v <= n; v++)
			{
				times.clear();
				dfs(u, v, 0);
				sort (times.begin(), times.end());
				int sum = 1;
				for (int i = 1; i < (int)times.size(); i++)
					if (times[i] == times[0]) sum++;
				if (sum == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
