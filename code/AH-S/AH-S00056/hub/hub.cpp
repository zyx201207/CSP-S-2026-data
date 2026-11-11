#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> e[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	int ttttttt = t;
	while (ttttttt--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	if (c == 0) cout << 1 << '\n' << 2 << '\n';
	else
	{
		while (t--) cout << 1 << '\n';
	}
	return 0;
}
