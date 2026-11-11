//Task1 crystal
/*
前缀和加二分法求解 
时间复杂度 
O(nlogn)
期望得分 100pts 
*/
#include <bits/stdc++.h>
using namespace std;
const long long N = 500005;
long long n, m, a[N], q[N], p[N], l, r, mid, ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	ans = 1;
	for (long long i = 1; i <= n; i++)
	{
		q[i] = a[i] - a[i - 1];
		p[i] = a[i] + p[i - 1];
		l = 1, r = i - 1;
		while(l < r)
		{
			mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - p[i] + p[mid - 1] <= m)
				r = mid;
			else
				l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	printf("%lld", ans);
}
