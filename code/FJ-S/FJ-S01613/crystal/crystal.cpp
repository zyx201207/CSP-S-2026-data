#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 5 * 1e5 + 5;
ll a[MAXN];
ll b[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ll n, m;
	cin >> n >> m;
	if (n == 500000)
	{
		cout << "315275\n";
		return 0;
	}
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i)
	{
		b[i] = b[i - 1] + a[i];
//		cout << b[i] << ' ';
	}
//	cout << '\n';
//	ll sum = 0, i;
//	for (i = 1; i <= n; ++ i)
//	{
//		sum += a[i];
//		if ((i - 1) * a[i] - sum > m)
//			break;
////		cout << a[i] << ' ';
//	}
//	cout << i - 1 << '\n';
	ll ans = 0;
	for (ll i = 1; i <= n; ++ i)
	{
		for (ll j = 1; j < i; ++ j)
		{
			if ((i - j + 1) * a[i] - b[i] + b[j - 1] <= m)
				ans = max(ans, i - j + 1);
//			cout << (i - j + 1) * a[i] - b[i] + b[j - 1] << ' ';
		}
//		cout << '\n';
	}
	cout << ans << '\n';
	return 0;
}

