#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll a[500010],d[500010],s[500010],ss[500010];
bool check(ll k)
{
	for (int i = 1 ; i <= n - k ; i++)
	{
		if (s[i + k - 1] * k + ss[i - 1] - ss[i + k - 2] <= m)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		scanf("%lld ",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for (int i = 2 ; i <= n ; i++)
	{
		d[i - 1] = a[i] - a[i - 1];
		s[i - 1] = s[i - 2] + d[i - 1];
		ss[i - 1] = ss[i - 2] + s[i - 1];
	}
	ll l = 1,r = n;
	ll mid;
	while (l < r)
	{
		mid = (l + r + 1) / 2;
		if (check(mid - 1))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
