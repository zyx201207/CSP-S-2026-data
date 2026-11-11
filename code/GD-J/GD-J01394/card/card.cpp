#include <bits/stdc++.h>
using namespace std;

#define int long long
map< int , int> mp;
const int N = 5e5 + 10;
int a[N];
signed main()
{
	freopen( "card.in" , "r" , stdin );
	freopen( "card.out" , "w" , stdout );
	int n , m;
	cin >> n >> m;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	 } 
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = i; j <= n; j++ )
		{
			mp[a[j]]++;
			for ( int k = i; k < j; k++ )
			{
				if ( a[j] == a[k] ) mp[a[k]]--;
			}
		}
	}
	for ( int i = 1;i <= m; i++ )
	{
		cout << mp[a[i]] << " ";
	}
	return 0;
}
