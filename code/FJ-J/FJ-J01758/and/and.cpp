#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005],b[200005];

int main (){
	freopen( "and.in", "r", stdin );
	freopen( "and.out", "w", stdout );
	scanf( "%d %d", &n, &m );
	for ( int i=1; i<=n; i++ ){
		scanf( "%lld", &a[i] );
	}
	sort( a+1, a+n+1, greater<long long>() );
	for ( int i=1; i<=n-m+1; i++ ){
		b[i] = a[i];
		for ( int j=1; j<m; j++ ){
			b[i] = b[i] & a[i+j];
		}
	}
	sort( b+1, b+n, greater<long long>() );
	printf( "%lld\n", b[1] );
	return 0;	
}

