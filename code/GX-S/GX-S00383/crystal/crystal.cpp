#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const int N = 5e5 + 10;
ll n, m, a[N], b[N], ans;

bool check(int x)
{
	for (int i = x; i <= n; i++)
		if ((b[i] - b[i - x]) <= m)
			return true;
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = (a[i] - a[i - 1]) * (i - 1) + b[i - 1];
	ll L = 0, R = n, mid;
	while (L <= R)
	{
		mid = (L + R) / 2;
		if (check(mid))
			ans = mid, L = mid + 1;
		else
			R = mid - 1;
	}
	cout << ans;

	return 0;
}
