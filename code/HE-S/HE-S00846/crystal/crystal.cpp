#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], ans, l, m, mid, n, r, sum[N];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std :: ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i ++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i ++)
	{
		l = i, r = n;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (a[i] * (mid - i + 1) - sum[mid] + sum[i - 1] <= m)
				l = mid + 1;
			else
				r = mid - 1;
		}
		ans = max(ans, l - i);
	}
	cout << ans;
	return 0;
}
