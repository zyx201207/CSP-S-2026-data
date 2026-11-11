#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;/*m和sum数组要开long long*/
const int MAXN = 5e5 + 10;
int n;
ll m, ans = 1;
int a[MAXN];
ll sum[MAXN];
bool check(int x, int y)
{
//	cout << "	check:" << a[x] * (x - y) - sum[x - 1] + sum[y - 1] << endl;
	return (a[x] * (x - y) - sum[x - 1] + sum[y - 1] <= m);/*最大1e18*/
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for ( int i = 1; i <= n; i++ )
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for ( int i = 2; i <= n; i++ )
	{
		for ( int l = 1, r = i - 1; l <= r; )
		{
			int mid = (l + r) >> 1;
			if ( check(i, mid) )
			{
//				cout << "debug:" << i << ' ' << ' ' << mid << ' ' << ans << endl;
				ans = max(ans, 1ll * i - mid + 1);
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
