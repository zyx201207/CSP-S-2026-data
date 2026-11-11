#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

inline ll r()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

const ll N = 5e5 + 5;
ll n, m, res, a[N], s[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = r(), m = r();
	for(ll i = 1; i <= n; i++)
	{
		a[i] = r();
	}
	sort(a + 1, a + 1 + n);
	for(ll i = 1; i <= n; i++)
	{
		s[i] = a[i] + s[i - 1];
	}
	for(ll i = 1; i <= n; i++)
	{
		ll l = 1, r = i;
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			if(abs(a[i] * (i - mid + 1) - (s[i] - s[mid - 1])) <= m)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		res = max(i - l + 1, res);
	}
	cout << res << '\n';
	return 0;
}
