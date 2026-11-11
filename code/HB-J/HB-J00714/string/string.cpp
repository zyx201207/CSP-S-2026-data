#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, l, r, ans, a[200010];
char c[200010];
signed main()
{
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	scanf("%lld", &n), l = 1, r = n;
	for (int i = 1; i <= n; i++)
		scanf("%lld %c", &a[i], &c[i]);
	while (l < r)
	{
		if (c[l] != c[r])
			ans += min(a[l], a[r]);
		if (a[l] < a[r])
			a[r] -= a[l], l++;
		else if (a[l] > a[r])
			a[l] -= a[r], r--;
		else
			l++, r--;
	}
	printf("%lld", ans);
	return 0;
}
