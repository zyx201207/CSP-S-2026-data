#include <cstdio>
using namespace std;
int a[200002];
char b[200002];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d %c", &a[i], &b[i]);
	}
	int li = 1, ri = n;
	int ll = a[1], rr = a[n];
	while (li < ri)
	{
		// printf("%d %d %d %d\n", li, ri, ll, rr);
		if (b[li] == b[ri])
		{
			if (ll <= rr)
			{
				rr -= ll;
				ll = 0;
			}
			else
			{
				ll -= rr;
				rr = 0;
			}
		}
		else
		{
			if (ll <= rr)
			{
				ans += ll;
				rr -= ll;
				ll = 0;
			}
			else
			{
				ans += rr;
				ll -= rr;
				rr = 0;
			}
		}
		if (ll == 0)
		{
			li ++;
			ll = a[li];
		}
		if (rr == 0)
		{
			ri --;
			rr = a[ri];
		}
	}
	printf("%lld", ans);
	return 0;
}