#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1, a+1+n);
	for (int i = 1;i <= n;i++)
	{
		if (m >= (a[i+1] - a[i])*(i-1))
		{
			m -= (a[i+1] - a[i])*(i-1);
			for (int j = 1;j <= i;j++)
				a[j] = a[i+1];
		}
		else break;
	}
	ll ans = 1;
	for (int i = 2;i <= n;i++)
	{
		if (a[i] != a[i-1]) break;
		ans++;
	}
	cout << ans;
}