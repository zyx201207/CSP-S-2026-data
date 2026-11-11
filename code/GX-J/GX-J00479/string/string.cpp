#include <bits/stdc++.h>
using namespace std;
long long n ;
string m ;
long long l ;
long long r ;
int main() {
	
	freopen( "string.in", "r", stdin );
	freopen( "string.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	cin >> n ;
	long long i,j ;
	for ( i=0; i<n; i++ ) {
		long long a ;
		char b ;
		cin >> a >> b ;
		for ( j=0; j<a; j++ ) {
			m+=b;
		}
	}
	l=0;
	r=m.size()-1;
	long long e=0 ;
	while ( l<r ) {
		if ( m[l]!=m[r] ) {
			e++;
		}
		l++;
		r--;
	}
	cout<< e ;
	
 return 0;
 }
