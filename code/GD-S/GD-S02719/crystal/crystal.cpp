#include <bits/stdc++.h>
using namespace std;

long long a[500005], s[500005], m, n;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int maxn = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = maxn; j <= i; j++)
		{
			long long sum = j * a[i] - s[j];
			if (sum <= m)
				maxn = j;
			else
				break;
		}
	}
	printf("%d", maxn);
	return 0;
}
