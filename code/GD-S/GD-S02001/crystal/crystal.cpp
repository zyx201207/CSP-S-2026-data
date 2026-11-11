#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], ans, sm;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	ans = 1;
	for (long long i = 1, j = 1; i <= n; i++)
	{
		sm += (i - j) * (a[i] - a[i - 1]);
		while (sm > m)
		{
			sm -= (a[i] - a[j]);
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
