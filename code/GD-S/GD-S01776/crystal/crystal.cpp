#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int w = 5e5 + 10;
const int inf = 0x3f3f3f3f;
ll n,m,a[w],cf[w],ans,s,ss;
bool spe1,spe2;
bool check(ll x)
{
	for (int i = 1;i <= n - x + 1;i++)
	{
		ll sum = 0;
		for (int j = i + 1;j <= i + x - 1;j++)
			sum += cf[j] * (j - i);
		if (sum <= m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	spe1 = true;
	spe2 = true;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != i)
			spe1 = false;
	}
	if (spe1)
	{
		ll cnt = 0;
		for (int i = 1;i <= n;i++)
		{
			cnt += i;
			if (cnt > m)
			{
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	sort(a + 1,a + n + 1);
	s++;
	ss++;
	for (int i = 1;i <= n;i++)
	{
		cf[i] = a[i] - a[i - 1];
		if (i >= 3)
		{
			if (cf[i] != cf[i - 1])
				spe2 = false; 
		}
		if (cf[i] == 0)
			ss = max(ss,++s);
		else
			s = 1;
	}
	if (spe2)
	{
		ll cnt = 0;
		for (int i = 1;i <= n;i++)
		{
			cnt += cf[2] * i;
			if (cnt > m)
			{
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	ll l = ss,r = n;
	while (l <= r)
	{
		ll mid = (l + r) >> 1;
		if (check(mid))
		{
			l = mid + 1;
			ans = max(ans,mid);
		}
		else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
