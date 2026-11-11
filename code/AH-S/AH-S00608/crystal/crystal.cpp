#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 12;
long long a[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int v = 1;
	int l = 1;
	long long c = 0;
	for (int i = 2; i <= n; i++)
	{
		c += 1ll * (a[i] - a[i - 1]) * (i - l);
		while (c > m)
		{
			c -= a[i] - a[l];
			l++;
		}
		v = max(v, i - l + 1);
	}
	printf("%d\n", v);
	return 0;
}
// 15:00 - 15:10, samples passed (54 ms), 100 points

