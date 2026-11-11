#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
int t , n , d , s [N] , c [N] , ans , a [N];
int f (int l , int r)
{
	if (l > (r - 4)) return 0;
	int last = l + 1 , cnt = 0;
	for (int j = l; j <= r - 4; j++)
	{
		if (c [j] > d) 
		{
			return cnt + f (j , r);
		}
		for (int k = last; k <= r; k++)
		{
			if (s [k] - s [j - 1] >= d)
			{
				if (k - j == 4) cnt++;
				last = k;
				break;
			}	
		}	
	}
	return cnt;	
}
signed main()
{
		freopen ("migrate.in" , "r" , stdin);
		freopen ("migrate.out" , "w" , stdout);
		cin >> t >> t;
		while ( t-- )
		{
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
			{
				cin >> a [i];
				c [i] = a [i] - a [i - 1];
				s [i] = s [i - 1] + a [i];
			} 
			if (d == 0 || d == 1)
			{
				cout << "0\n";
				continue;
			}
			bool flag = 0;
			for (int i = 2; i <= n; i++)
			{
				if (c [i] != c [i - 1]) 
				{
					flag = 1;
					break;
				}
			}
			if ( !flag )
			{
				int x = c [2];
				int ans = n - ((d / x) << 1) + 1;
				if (d <= x) cout << 0 << "\n";
				else cout << ans << "\n";
				continue;
				//else cout << max (0 , ans);
			}
		    cout << f (1 , n) << "\n";
		}
		return 0;
}

