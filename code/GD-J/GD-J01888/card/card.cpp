#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, a[N], b[M], top; pair < int, bool > vis[M];
int main () {
	freopen ( "card.in", "r", stdin );
	freopen ( "card.out", "w", stdout );
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for ( int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	for ( int i = 1; i <= n; i ++ ) {
		top = 0;
		for ( int j = 1; j <= m; j ++ ) {
			vis[a[j]].first = vis[a[j]].second = 0;
		}
		for ( int k = i; k <= n; k ++ ) {
			if ( vis[a[i]].second ) {
				int z = top;
				top = vis[a[i]].first - 1;
				for ( int j = vis[a[i]].first; j <= z; j ++ ) {
					vis[a[j]].first = 0;
					vis[a[j]].second = 0;
				}
			}
			else vis[a[i]].second = 1, vis[a[i]].first = ++ top;
		}
		for ( int j = 1; j <= n; j ++ ) {
			b[j] += vis[a[i]].second; 
		}
	}
	for ( int i = 1; i <= n; i ++ )
		cout << b[i] << ' ';
	return 0;
}
