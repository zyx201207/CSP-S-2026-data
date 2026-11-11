#include <bits/stdc++.h>
using namespace std;
int main() {
	
	freopen( "card.in", "r", stdin );
	freopen( "card.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	long long n,m ;
	cin >> n >> m ;
	long long p[m+1] ;
	long long x[n+1] ;
	memset( p, 0, sizeof(p) );
	long long i,l,j ;
	for ( i=0; i<n; i++ ) {
		cin >> x[i] ;
	}
	for ( i=0; i<n; i++ ) {
		long long z[n+1] ;
		memset( z, -1, sizeof(z) );
		for ( l=i; l<n; l++ ) {
			for ( j=0; j<n; j++ ) {
				if ( z[j]==-1 ) {
					z[j]=x[l];
					z[j+1]=-1;
					break;
				}
				if ( z[j]==x[l] ) {
					z[j+1]=-1;
					break;
				}
			}
		}
		for ( l=0; l<n; l++ ) {
			if ( z[l]==-1 ) {
				break;
			}
			p[z[l]]++;
		}
	}
	for ( i=1; i<=m; i++ ) {
		cout<< p[i] << ' ' ;
	}
	
 return 0;
 }
