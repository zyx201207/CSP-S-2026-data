#include <bits/stdc++.h>
using namespace std;

int n , m , s , mx = -1e9;
int a[100005];

int main ()
{
	freopen ( "and.in" , "r" , stdin );
	freopen ( "and.out" , "w" , stdout );
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[i];
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		s = ( a[i] & a[i + 1] );
		mx = max ( mx , s );
	}
	cout << mx;
	
	return 0;
}

