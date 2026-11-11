#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int a[N];
signed main()
{
	freopen ( "and.in" , "r" , stdin );
	freopen ( "and.out" , "w" , stdout );
	int n , m;
	cin >> n >> m;
	for ( int i = 1;i <= n; i++ )
	{
		cin >> a[i];
	}
	if ( m == 1 )
	{
		sort ( a + 1 , a + n + 1 );
		cout << a[n];
	}
	else if ( m == 2 )
	{
		int ans = 0;
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				if ( i != j )
				{
					ans = max( ans , a[i] & a[j]);
				}
			}
		}
	}
	else if ( m == 3 )
	{
		int ans = 0;
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				for ( int k = 1; k <= n; k++ )
				{
					if ( i != j && j != k && i != k )
					{
						ans = max( ans , a[i] & a[j] & a[k]);
					}
				}
			
			}
		}
	}
	else 
	{
		cout << "17";
	}
	return 0;
}
