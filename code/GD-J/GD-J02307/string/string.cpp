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
long long a[200005];
char b[200005];
int main()
{
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout );
	cin.tie( nullptr );
	cout.tie( nullptr );
	ios::sync_with_stdio( false );
	int n , num = 0;
	long long ans = 0;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ )
	{
		num ++;
		cin >> a[num] >> b[num];
		if ( b[num] == b[num - 1] )
		{
			a[num - 1] += a[num];
			a[num] = 0;
			num --;
		}
	}
	int i = 1 , j = num;
	while ( i < j )
	{
		long long f = min( a[i] , a[j] );
		if ( b[i] != b[j] )
		{
			ans += f;
		}
		a[i] -= f;
		a[j] -= f;
		if ( a[i] == 0 )
		{
			i ++;
		}
		if ( a[j] == 0 )
		{
			j --;
		}
	}
	cout << ans;
	return 0;
}
