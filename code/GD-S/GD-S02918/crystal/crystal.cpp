#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll n, m;
ll a[500005];
ll pre[500005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1); // 19 * 500000
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
//		cout << pre[i] << ' ';
	}
	
	ll ans = 0;
	ll i = 1, j = 1;
	for (; i <= n; i++)
	{
		for (j = min(j, n); j <= n; j++)
		{
			ll cost = (j - i) * a[j] - (pre[j - 1] - pre[i - 1]);
//			cout << "´Ó" << i << "µ½" << j << " " << cost << '\n';
			if (cost <= m) ans = max(ans, (ll)(j - i + 1));
			else break;
		}
	}
	cout << ans << '\n';
	return 0;
} 

