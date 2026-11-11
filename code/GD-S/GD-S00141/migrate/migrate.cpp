#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll a[N], n, d;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ll x = a[2] - a[1];
		if (x > d)
			cout << 0 << "\n";
		else
		{
			ll k = d / x, y = n % k, cnt = n / k;
			cout << y << "\n";
		}
	}
	return 0;
}
