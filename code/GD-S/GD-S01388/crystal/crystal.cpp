#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 10;
ll n, m;
ll a[N];
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	ll l = 1, sum = 0;
	ans = 1;
	for (int i = 2; i <= n; i++)
	{
		while (sum + (i - l) * (a[i] - a[i - 1]) > m)
		{
			sum -= a[i - 1] - a[l];
			l++;
		}
		sum += (i - l) * (a[i] - a[i - 1]);
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
