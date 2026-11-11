#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int a[N] , s[N];
int ans;
signed main()
{
	freopen( "crystal.in" , "r" , stdin );
	freopen( "crystal.out" , "w" , stdout );
	int n , m;
	cin >> n >> m;
	
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		memset ( s , 0 , sizeof(s) );
		int l = m;
		for ( int j = 1; j <= n; j++ )
		{
			s[j] = abs( a[i] - a[j] );
		}
		
		sort ( s + 1 , s + n + 1 );
		int sum = 0 , cnt = 0;
		for ( int i = 1;i <= n; i++ )
		{
			if ( sum + s[i] <= l ) 
			{
				sum += s[i];
				cnt = i;
			}
			else 
			{
				break;
			}
		}
		ans = max( ans , cnt );
	}
	cout << ans;
	return 0;
}
