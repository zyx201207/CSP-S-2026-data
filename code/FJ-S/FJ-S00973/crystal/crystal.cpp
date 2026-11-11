#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
const LL N = 5e5 + 10;

LL a[N];

void solve()
{
	LL n, m; scanf("%lld%lld", &n, &m);
	for (LL i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	LL res = 1, l = 1, sum = 0;
	for (LL i = 2; i <= n; i ++ )
	{
		sum += (a[i] - a[i - 1]) * (i - l);
		while (sum > m) sum -= (a[i] - a[l]), l ++ ;
		res = max(res, i - l + 1);
	}
	printf("%lld\n", res);
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	LL T = 1;
	while (T -- ) solve();
	return 0;
}
