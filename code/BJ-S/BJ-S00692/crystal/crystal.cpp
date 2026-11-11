#include <algorithm>
#include <iostream>
using namespace std;

long long n, m, a[500005], s[500005];

bool check(long long x)
{
	long long minn = 9e18;
	for (int i = x; i <= n; ++i) minn = min(minn, a[i] * (x - 1) - s[i - 1] + s[i - x]);
	return minn <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	long long l = 0, r = n;
	while (l <= r)
	{
		long long mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << '\n';
	return 0;
}