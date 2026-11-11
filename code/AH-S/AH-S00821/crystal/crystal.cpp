#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll n, m;
ll a[N];
ll sum[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		if (i > 1)
		{
			ll l = 1, r = i;
			while(l <= r)
			{
				ll mid = (l + r) / 2;
				if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m)
				{
					r = mid - 1;
				}
				else l = mid + 1;
			}
			ans = max(ans, (i - l + 1));
		}
	}
	
	cout << ans << endl;
	return 0;
} //Oct31==Dec25?
