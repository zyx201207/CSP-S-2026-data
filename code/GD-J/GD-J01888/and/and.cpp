#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, cnt, a[N], word[N], tree[2][N], size[N]; bool vis[N];
void dfs ( int ans, int step ) {
	if ( step == m ) {
		cnt = max ( cnt, ans );
		return ;
	}
	for ( int i = 1; i <= n; i ++ ) {
		if ( !vis[i] ) {
			vis[i] = 1;
			dfs ( ans & a[i], step + 1);
			vis[i] = 0;
		}
	}
}
void built ( int u ) {
	for ( int i = 29; i >= 0; i -- ) {
		if ( (1 << i) & u ) {
			size[(1 << (30 - i))] ++;
			u -= (1 << i);
			if ( u == 0 ) {
				word[1 << ( 30 - i )] ++;
				break;
			}
		}
		else {
			size[(1 << (30 - i)) + 1] ++;			
		}
	}
}
int find( int x ) {
	int ans = 0;
	if ( size[x] == m ) {
		while ( size[x * 2] == m || size[x * 2 + 1] == m ) {
			if ( size[x * 2] == m ) x *= 2;
			else x = x * 2 + 1;
		}
		while ( x >= 1 ) {
			if ( ((x / 2) & 1) == 0 ) {
				ans += (1 << ( 30 - x / 2 ) );
			}
			x /= 2;
		}
	}
	else if ( size[x] > m ) {
		if ( size[x / 2] >= m ) ans = max ( ans, find ( x / 2 ) );
		if ( size[x / 2 + 1] >= m ) ans = max ( ans, find ( x / 2 + 1 ) );
		if ( size[x / 2] < m && size[x / 2 + 1] < m )  {
			while ( x >= 1 ) {
				if ( ((x / 2) & 1) == 0 ) {
					ans += (1 << ( 30 - x / 2 ) );
				}
				x /= 2;
			}
		}
	}
	return ans;
}
int main () {
	freopen ( "and.in", "r", stdin );
	freopen ( "and.out", "w", stdout );
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for ( int i = 1; i <= n; i ++ )
		cin >> a[i];
	if ( n == m ) {
		int ans = a[1];
		for ( int i = 2; i <= n; i ++ )
			ans &= a[i];
		cout << ans << '\n';
		return 0; 
	}
	if ( m == 1 ) {
		int M = -1e9;
		for ( int i = 1; i <= n; i ++ )
			M = max ( M, a[i] );
		cout << M << '\n';
		return 0;
	}
	dfs ( (1LL << 30) - 1, 0 );
	cout << cnt << '\n';
	/*for ( int i = 1; i <= n; i ++ )
		built( a[i] );
	cout << find ( 1 ) << '\n';*/
	return 0;
}
