#include <bits/stdc++.h>
using namespace std ;
int n , m , c , d , q , x , y ;
int e[500005] ;
long long sum , t[500005][55] ;
bool s[500005] ;
int w[500005] , a[500005][55] , k[500005] , to[500005][55] ;
void dfsA (int num , long long time) {
//	if (e[num] == 1) return ;
	if (s[num]) return ;
	if (num == y) {
		sum = min (sum , time) ;
		return ;
	}
	for (int i = 1 ; i <= e[num] ; i++) {
		for (int j = 1 ; j <= 2 ; j++) {
			if (a[ to[num][i] ][j] != num && e[num] != 1) {
				s[num] = 1 ;
				dfsA (a[ to[num][i] ][j] , time + t[ to[num][i] ][j]) ;
				s[num] = 0 ;
			}
		}
	}
}
void fA () {
//	cout << "@" ;
	sum = 1000000000000000000 ;
	if (x == y) {
		cout << w[x] << endl ;
		return ;
	}
	dfsA (x , w[x] + w[y]) ;
	cout << sum << endl ;
}
void f () {
	if (c >= 7 && c <= 11) fA () ;
}
int main () {
	freopen ("subway.in" , "r" , stdin) ;
	freopen ("subway.out" , "w" , stdout) ;
	cin >> c >> n >> m >> d >> q ;
	for (int i = 1 ; i <= m ; i++) {
		cin >> w[i] ;
	}
	for (int i = 1 ; i <= n ; i++) {
		cin >> k[i] ;
		for (int j = 1 ; j <= k[i] ; j++) {
			cin >> a[i][j] >> t[i][j] ;
			e[a[i][j]]++ ;
			to[a[i][j]][e[a[i][j]]] = i ;
		}
	}
	for (int i = 1 ; i <= q ; i++) {
		cin >> x >> y ;
//		cout << i << " " ;
		f () ;
	}
	return 0 ;
}
