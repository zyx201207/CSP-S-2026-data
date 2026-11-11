#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N];
bool vis[N];

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 29; i >= 0; --i)
	{
		int sum = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (vis[j])
				continue ;
			if (a[j] & (1 << i))
				++sum;
		}
		if (sum >= m)
		{
			ans += (1 << i);
			for (int j = 1; j <= n; ++j)
				if (!(a[j] & (1 << i)))
					vis[j] = 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
