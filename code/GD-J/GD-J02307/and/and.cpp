#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
int a[200005] , ans = -1 , n , m;
void xmm( int i , int num , int b )
{
	if ( num >= m )
	{
		ans = max( ans , b );
		return;
	}
	if ( b <= ans || i > n )
	{
		return;
	}
	xmm( i + 1 , num + 1 , ( b & a[i] ) );
	if ( num + n - i >= m )
	{
		xmm( i + 1 , num , b );
	}
	return;
}
int main()
{
	freopen( "and.in" , "r" , stdin );
	freopen( "and.out" , "w" , stdout );
	cin.tie( nullptr );
	cout.tie( nullptr );
	ios::sync_with_stdio( false );
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> a[i];
	xmm( 1 , 0 , 0x7FFFFFFF );
	cout << ans; 
	return 0;
}
