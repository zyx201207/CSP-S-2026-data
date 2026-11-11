#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, a[2000005];
vector<int> g;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t; 
	for (int q = 1; q <= t; q++)
	{
		cin >> n >> d >> a[1];
		bool flag = true;
		for (int i = 2; i <= n; i++)
		{
			cin >> a[i];
			g.push_back(a[i] - a[i - 1]);
			if (i == 2) continue;
			if (g[i] != g[i - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << n - d * 2 + 1 << endl;
		}
	}
	return 0;
}
