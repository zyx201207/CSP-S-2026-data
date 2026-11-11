/*
crystal 1s 1024M
two-pointer, greedy
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 5;
int n, res = 0;
LL m, a[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i ++)scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	LL sum = 0;
	for (int l = 1, r = 1; r <= n; r ++)
	{
		sum += a[r];
		while (l <= r && (1LL * (r - l + 1) * a[r]) - sum > m)sum -= a[l ++];
		res = max(res, r - l + 1);
	}
	printf("%d", res);
    return 0;
}
