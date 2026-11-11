#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 2e6 + 10;
int a[N] , s[N];
signed main()
{
	freopen( "migrate.in" , "r" , stdin );
	freopen( "migrate.out" , "w" , stdout );
	int c , t;
	cin >> c >> t;
	while ( t-- )
	{
		memset ( a , 0 , sizeof( a ) );
		memset ( s , 0 , sizeof( s ) );
		int n , d;
		cin >> n >> d;
		int cnt = 0;
		for ( int i = 1;i <= n; i++ ) 
		{
			cin >> s[i];
			if ( i == 1 )
			{
				cnt++;
				a[cnt] = s[i];
			}
			if ( i != 1 && s[i] - s[i - 1] <= d ) 
			{
				cnt++;
				a[cnt] = s[i];
			}
		}
		int ans = 0;
		for ( int i = 1; i <= cnt - 3; i++ )
		{
			if ( a[i + 3] > a[i] + d ) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
