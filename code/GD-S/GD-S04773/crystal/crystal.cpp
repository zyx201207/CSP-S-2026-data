#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
ll m;
ll a[500000];
//ll b[500000];
ll ans;
//ll s;

/** int sigma()
{
	int m1 = m;
	s= 1;
	while(m1 >= 0)
	{
		for (int i = 0; i < n; ++i)
		{
			m1 -= b[i];
			if(m1 >= 0)
			{
				++s;
			}
			else
			{
				break;
			}
		}
	}
	return s;
} */

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	int m2 = 0;
	int bg = 0;
	for (int i = 0; i < n; ++i)
	{
		m2 = 0;
		for (int j = i; j >= 0; --j)
		{
			m2 += a[i] - a[j];
			if (m2 > m)
			{	
				break;
			}
			if ((i-j + 1) > bg)
			{
				bg = (i - j + 1);
			}
		}
		
	}
	/*ll ltt = 1e18;
	int ltta;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j] > a[i])
			{
				b[j] += a[j] - a[i];
			}
			else
			{
				b[j] += a[i] - a[j];
			}

		}
		if (b[i] < ltt)
		{
			ltt = b[i];
			ltta = i;
		}
	}
	for (int i = 0; i <= ltta; ++i)
	{
		if (a[i] > a[ltta])
			{
				b[i] = a[i] - a[ltta];
			}
			else
			{
				b[i] = a[ltta] - a[i];
			}
	}
	sort(b, b + n);
	int m1 = m;
	s= 1;
	while(m1 >= 0)
	{
		for (int i = 0; i < n; ++i)
		{
			m1 -= b[i];
			if(m1 >= 0)
			{
				++s;
			}
			else
			{
				break;
			}
		}
	}*/
	ans = bg;
	cout << ans;
	
	return 0;
}
