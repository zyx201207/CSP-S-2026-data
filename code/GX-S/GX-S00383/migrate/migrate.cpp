#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const int N = 2e6 + 10;
int c, t;
ll n, d, a[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int f = a[2] - a[1];
		if (f > d)
		{
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= n; i++)
			if (upper_bound(a + 1, a + n + 1, a[i] + d) != lower_bound(a + 1, a + n + 1, a[i] + d))
				ans++;
		cout << ans << '\n';
	}

	return 0;
}

