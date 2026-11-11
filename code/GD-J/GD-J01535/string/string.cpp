#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5; 
#define int long long
int n , a[N] , sum ;
char ch[N];
signed main() {
	freopen ( "string.in" , "r" , stdin );
	freopen ( "string.out" , "w" , stdout );
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n; 
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] >> ch[i] ;
	}
	int l = 1 , r = n ;
	while ( l < r ) {
		if ( ch[l] != ch[r] ) {
			sum += min ( a[l] , a[r] );
		}
		int k = min ( a[l] , a[r] );
		a[l] -= k , a[r] -= k;
		if ( a[l] == 0 ) l ++ ;
		if ( a[r] == 0 ) r -- ;
	}
	cout << sum;
	return 0;
}
