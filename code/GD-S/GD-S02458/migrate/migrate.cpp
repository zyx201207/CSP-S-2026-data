#include <cstdio>
#include <iostream>
using namespace std;
const int N(2e6 + 5);
long long a[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.in", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int c, t;
	long long ans = 0;
	cin >> c >> t;
	for (int i = 1, n, d; i <= t; i++)
	{
		ans = 0;
		cin >> n >> d;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j];
		}
		if (a[3] - a[2] == a[2] - a[1] && a[3] - a[2] > d)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int j = 1; j <= n - 3; j++)
		{
			if ((a[j + 3] - a[j + 2] <= d) && (a[j + 2] - a[j + 1] <= d) && (a[j + 1] - a[j] <= d))
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
