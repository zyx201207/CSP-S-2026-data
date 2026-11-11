#include <bits/stdc++.h>
using namespace std;

int c, t, n;
long long d, x[2000005];

void Main()
{
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	int a = lower_bound(x + 1, x + n + 1, x[1] + d) - x, ans = 0;
	for (int i = a; i <= n; i++)
	{
		int t = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
		if ((i - t == 2 && t != 1) || (i - t == 3 && t == 1))
			ans++;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
		Main();
	return 0;
}
