#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 5e5 + 5;
LL n, a[maxn], sum[maxn], m, ans, o;
LL ef(LL x, LL y) // find q -> sum[q - 1] - a[y] * q <= x
{
	LL l = 1, r = y, mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
//		cout << y << ' ' << mid << ' ' << sum[mid - 1] - a[y] * mid << ' ' << x << '\n';
		if(sum[mid - 1] - a[y] * mid > x) l = mid + 1;
		else r = mid - 1;
//		cout << y << ' ' << l << ' ' << r << '\n';
	}
	return l;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for(int i = 3; i <= n; i++)
	{
//		if(a[i] * (i - 1) - sum[i - 1] <= m) ans = max(ans, (LL)i);
		ans = max(ans, 1 + i - ef(m - a[i] * i + sum[i - 1], i));
//		cout << i << ' ' << ans << '\n';
	}
	printf("%lld", ans);
	return 0;
 } 
