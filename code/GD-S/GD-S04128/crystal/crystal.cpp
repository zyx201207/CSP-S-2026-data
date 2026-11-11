#include<bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int n, l = 0, r;
long long ans, m, a[maxn], b[maxn];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i)
	{
		b[i] = b[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++ i)
	{
		int ret = 0;
		r = i;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if ((i - mid - 1) * a[i] - (b[i - 1] - b[mid]) <= m)
			{
				r = mid - 1;
				ret = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans, (long long)i - ret);
	}
	cout << ans;
	return 0;
}

