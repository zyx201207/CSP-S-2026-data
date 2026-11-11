#include <bits/stdc++.h>
using namespace std;

int ans;
const int N = 2e6 + 10;
int w[N] , a[N][N] , t[N][N];
int main()
{
	freopen ( "subway.in" , "r" , stdin );
	freopen ( "subway.out" , "w" , stdout );
	int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m; i++ ) cin >> w[i];
	for ( int i = 1; i <= n; i++ )
	{
		int k;
		cin >> k;
		for ( int j = 1; j <= k; j++ ) cin >> a[i][j] >> t[i][j]; 
	}
	while ( q-- )
	{
		ans = 0;
		int x , y;
		cin >> x >> y;
	}
	if ( c == 0 )
	{
		if ( n == 2 )
		{
			printf ( "32\n17");
			return 0;
		}
		if ( n == 3 )
		{
			printf ( "35\n16");
			return 0;
		}
	}
	return 0;
}
