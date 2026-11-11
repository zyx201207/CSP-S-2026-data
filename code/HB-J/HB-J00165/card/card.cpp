# include <bits/stdc++.h>
using namespace std;

int p1[5001] , p2[5001];
int n , m , c[5001][5001] , t[5001] , a[5001] , o[3001] , p;

int main ( ) {
	freopen ( "card1.in" , "r" , stdin );
	//freopen ( "card.out" , "w" , stdout );
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
		if ( o[a[i]] )
			p1[i] = o[a[i]] , p2[o[a[i]]] = i;
		o[a[i]] = i;
	}
	int sum [3001];
	for ( int p = 1 ; p <= n ; p++ ){
		for ( int i = p ; i <= n ; i++ ){
			sum[a[i]]++;
			if ( p2[i] )
				i = p2[i];
		}
	}
	for ( int i = 1 ; i <= m ; i++ )
		cout << sum[i] << ' ';
}
