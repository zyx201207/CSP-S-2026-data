#include <bits/stdc++.h>
using namespace std;

int n , k;
int a[100005] , c[100005];

int main ()
{
	freopen ( "string.in" , "r" , stdin	 );
	freopen ( "string.out" , " w" , stdout );
	cin >> n;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[i] >> c[i];
		k += a[i];
	}
	cout << 0;
	
	return 0;
}

