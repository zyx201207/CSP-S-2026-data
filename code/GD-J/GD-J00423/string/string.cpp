#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , a[200005] , ans;
char c[200005];
signed main ()
{

	freopen ("string.in" , "r" , stdin);
	freopen ("string.out" , "w" , stdout);
	ios::sync_with_stdio (NULL);
	cin.tie (0);
	cout.tie (0);
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i] >> c[i];
	}
	for (int i = 1 , j = n;i < j;)
	{
		if (a[i] > a[j])
		{
			if (c[i] != c[j])
			{
				ans += a[j];
			}
			a[i] -= a[j];
			j --;
		}
		else if (a[i] < a[j])
		{
			if (c[i] != c[j])
			{
				ans += a[i];
			}
			a[j] -= a[i];
			i ++;
		}
		else 
		{
			if (c[i] != c[j])
			{
				ans += a[j];
			}
			i ++;
			j --;
		}
	}
	cout << ans;
	return 0;
}

