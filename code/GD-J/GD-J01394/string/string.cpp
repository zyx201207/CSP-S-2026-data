#include <bits/stdc++.h>
using namespace std;

#define int long long
int sum , ans;
const int N = 2e7 + 10;
char a[N];
signed main()
{
	freopen ( "string.in" , "r" , stdin );
	freopen ( "string.out" , "w" , stdout );
	int n;
	cin >> n;
	for ( int i = 1; i<= n; i++ )
	{
		int m;
		char x;
		cin >> m >> x;
		while ( m-- )
		{
			a[++sum] = x;
		}
	}
	for ( int i = 1; i <= sum / 2; i++ )
	{
		if ( a[i] != a[sum + 1 - i] )
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
