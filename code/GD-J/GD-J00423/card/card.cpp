#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m , a[5005] , ans[3005] , k[3005] , p[3005];
signed main ()
{

	freopen ("card.in" , "r" , stdin);
	freopen ("card.out" , "w" , stdout);
	ios::sync_with_stdio (NULL);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		memset (k , 0 , sizeof k);		
		memset (p , 0 , sizeof p);		
		for (int j = i;j <= n;j ++)
		{
			if (k[a[j]] != 0)
			{
				for (int l = p[a[j]];l <= j;l ++)
				{
					k[a[l]] = 0;
					p[a[l]] = 0;
				}
				k[a[j]] = 1;
				p[a[j]] = j;
			}
			else
			{
				k[a[j]] = 1;
				p[a[j]] = j;
			}
		}
		for (int j = 1;j <= m;j ++)
		{
			if (k[j] == 1)
			{
				ans[j] ++;
			}
		}
	}
	for (int i = 1;i <= m;i ++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}

