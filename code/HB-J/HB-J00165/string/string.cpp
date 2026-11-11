# include <bits/stdc++.h>
using namespace std;

int l , l1 , r , r1 , a[200001] , n;
char s[200001];

int main ( ) {
	freopen ( "string.in" , "r" , stdin );
	freopen ( "string.out" , "w" , stdout );
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ )
		scanf ( "%d %c" , &a[i] , &s[i] );
	l = 1 , r = n;
	long long sum = 0;
	for ( int i = 1 ; i <= n ; i++ ) {
		int t = min ( a[l] , a[r] );
		a[l] -= t;
		a[r] -= t;
		if ( s[l] != s[r] )
			sum += t;
		if ( a[l] == 0 )
			l++;
		if ( a[r] == 0 )
			r--;
	}
	cout << sum;
}
