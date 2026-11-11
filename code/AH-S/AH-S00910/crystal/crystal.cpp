#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005], sum[500005], m;
void read(int& e)
{
	e = 0;
	char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	bool f = 0;
	if (c == '-') f = 1, c = getchar();
	while (isdigit(c)) e = (e << 3) + (e << 1) + (c - '0'), c = getchar();
	if (f) e = -e;
}
bool check(int mid, int i)
{
	int k = i - mid + 1;
	return a[i] * k - sum[i] + sum[mid - 1] <= m;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, ret = 1; read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i, ans = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (check(mid, i))
				r = mid - 1, ans = mid;
			else
				l = mid + 1;
		}
		ret = max(i - ans + 1, ret);
	}
	printf("%lld", ret);
	return 0;
}
