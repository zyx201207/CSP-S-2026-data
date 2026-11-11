#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], maxa, ahora;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i+m <= n+1; i++)
	{
		ahora = a[i];
		for (int j = i+1; j <= i+m-2; j++)
		{
			ahora = (ahora & a[j]);
		}
		if (ahora > maxa)
		{
			maxa = ahora;
		}
	}
	printf("%lld\n", maxa);
	return 0;
}
