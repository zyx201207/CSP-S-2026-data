/*
migrate, 1s, 1024M 
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
typedef long long LL;
int c, n, d[N], f[N], sum[N];
LL x[N], l;
void work()
{
	LL res = 0;
	scanf("%d%lld", &n, &l);
	for (int i = 1; i <= n; i ++)scanf("%lld", &x[i]);
	if (n == 1)
	{
		puts("0");
		return;
	}
	if (c == 11 || c == 12)
	{
		LL dist = x[2] - x[1];
		LL k = (l / dist);
		if (k < 2)puts("0");
		else
		{
			k = k * 2 - 1;
			printf("%lld\n", max(0LL, n - k));
		}
		return;
	}
	for (int s = 1; s <= n; s ++)
	{
		int t = s + 1, z = s + 1;
		while (t <= n && x[t] - x[s] <= l)
		{
			sum[d[t] = 1] += (f[t] = 1);
			t ++;
		}
		for (; t <= n; t ++)
		{
			while (z < t && x[t] - x[z] > l)
			{
				sum[d[z]] -= f[z];
				z ++;
			}
			if (z == t)break;
			sum[(d[t] = d[z] + 1)] += (f[t] = sum[d[z]]);
			if (f[t] == 2)res ++;
		}
		for (int i = 1; i <= n; i ++)d[i] = f[i] = sum[i] = 0;
	}
	printf("%lld\n", res);
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	int T;
	scanf("%d%d", &c, &T);
	while (T --)work();
    return 0;
}
