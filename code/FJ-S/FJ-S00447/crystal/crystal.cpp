#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 5;
typedef long long ll;
int n;
ll m;
ll a[MAXN], sum[MAXN];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = -114;
	for (int i = 1; i <= n; i++)
	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			bool flag = 0;
//			ll x = a[j];
//			ll qx = (x * (j - i + 1)) - (sum[j] - sum[i - 1]);
//			if (qx <= m)
//				ans = max(ans, j - i + 1);
//		}
		ll l = i, r = n;
		ll pos = -114;
		while (l <= r)
		{
			ll mid = (l + r) >> 1;
			ll x = a[mid];
			ll qx = (x * (mid - i + 1)) - (sum[mid] - sum[i - 1]);
			if (qx <= m)
			{
				l = mid + 1;
				pos = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		ans = max(ans, pos - i + 1);
	}
	cout << ans << '\n';
	return 0;
}
