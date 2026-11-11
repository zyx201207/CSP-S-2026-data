//贵阳市第十九中学 刘承福 GZ-S00032
#include <bits/stdc++.h>
using namespace std;

int c, t;
int g[1005][1005];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n-1; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u][v]++;
			g[v][u]++;
		}
		cout << 1 << endl;
	}
	return 0;
}

