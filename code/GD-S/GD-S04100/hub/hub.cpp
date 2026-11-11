#include <bits/stdc++.h>
using namespace std;

int c, t, n, k, u, v;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i < n; i++) cin >> u >> v;
		cout << k / 2 << "\n";
	}
	return 0;
}
