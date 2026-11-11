#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
long long a[500005];
int main()
{
	freopen( "crystal.in" , "r" , stdin );
	freopen( "crystal.out" , "w" , stdout );
	cin.tie( nullptr );
	cout.tie( nullptr );
	ios::sync_with_stdio( false );
	long long n , m;
	long long ans = 1;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i];
	}
	sort( a + 1 , a + n + 1 );
	bool b = 1;
	long long e = a[2] - a[1];
	for ( int i = 2 ; i <= n ; i++ )
	{
		if ( a[i + 1] - a[i] != e )
		{
			b = 0;
			break;
		}
	}
	if ( b == 1 )
	{
		long long num = 0 , i = 1;
		for ( i = 1 ; i <= n ; i++ )
		{
			if ( num + 1ll * i * e <= m )
			{
				num += 1ll * i * e;
			}
			else
				break;
		}
		cout << i;
		return 0;
	}
	a[n + 1] = 0x7FFFFFFFFFFFFFFF;
	for ( int i = 1 ; i <= n ; i++ )
	{
		if ( a[i] != a[i + 1] )
		{
			long long num = 0 , f = 1;
			for ( int j = i - 1 ; j >= 1 ; j-- )
			{
				if ( num + a[i] - a[j] <= m )
				{
					num += a[i] - a[j];
					f ++;
				}
				else
					break;
			}
			ans = max( f , ans );
		}
	}
	cout << ans;
	return 0;
}
