#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
int a[500005] , ans[300005];
bool b[300005];
stack<int> s;
int main()
{
	freopen( "card.in" , "r" , stdin );
	freopen( "card.out" , "w" , stdout );
	cin.tie( nullptr );
	cout.tie( nullptr );
	ios::sync_with_stdio( false );
	int n = 0 , m = 0;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> a[i];
	for ( int i = 1 ; i <= n ; i++ )
	{
		memset( b , 0 , sizeof( b ) );
		stack<int> s;
		for ( int j = i ; j <= n ; j++ )
		{
			if ( b[a[j]] )
			{
				while ( s.top() != a[j] )
				{
					b[s.top()] = 0;
					ans[s.top()] --;
					s.pop();
				}
				b[a[j]] = 0;
				ans[a[j]] --;
				s.pop();
			}
			b[a[j]] = 1;
			ans[a[j]] ++;
			s.emplace( a[j] );
		}
	}
	
	for ( int i = 1 ; i <= m ; i++ )
		cout << ans[i] << ' ';
	return 0;
}
