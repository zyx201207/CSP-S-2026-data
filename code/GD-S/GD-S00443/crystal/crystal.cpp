#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m , a[500005] , s[500005] , ans , p;
int check (int x)
{
	//cout << abs ((s[p] - s[x - 1]) - (p - x + 1) * a[p]) << "\n";
	return abs ((s[p] - s[x - 1]) - (p - x + 1) * a[p]) > m;
}
int ef ()
{
	int l = 1 , r = p + 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		//cout << l << " " <<  r << " " << mid << ":";
		if (check (mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l - 1;
}
signed main ()
{
	
	freopen ("crystal.in" , "r" , stdin);
	freopen ("crystal.out" , "w" , stdout);
	ios::sync_with_stdio (NULL);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort (a + 1 , a + n + 1);
	for (int i = 1;i <= n;i ++)
	{
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		p = i;
		ans = max (i - ef () , ans);
	}
	cout << ans;
	return 0;
}
