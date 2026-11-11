#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
ll n, m;
ll a[N], s[N], sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 2; i <= n; i++)
	{
		s[i] = a[i]-a[i-1];
		sum[N] = sum[i]+s[i];
	}
	ll lst = 0;
	int ans = 1, maxn = 0;
	int begin = 1;
	for (int i = 2; i <= n; i++)
	{
		ll id = (ll)(i-begin);
		while ((m-lst) / id < s[i])
		{
			maxn = max(ans, maxn);
			ans--;
			lst -= sum[i-1]-sum[begin];
			begin++;
			id--;
			if (begin == i)
			{
				break;
			}
		}
		lst += s[i]*id;
		ans++;
	}
	cout << maxn << '\n';
	return 0;
}
