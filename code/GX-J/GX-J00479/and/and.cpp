#include <bits/stdc++.h>
using namespace std;
int n,m ;
int x[100010] ;
int p[100010] ;
int main() {
	
	freopen( "and.in", "r", stdin );
	freopen( "and.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	cin >> n >> m ;
	int a,b,c,d,e,f ;
	for ( a=0; a<n; a++ ) {
		cin >> x[a] ;
	}
	int MAX=-1 ;
	if ( m==2 ) {
		
		for ( a=0; a<n-1; a++ ) {
			for ( b=a+1; b<n; b++ ) {
				MAX=max( MAX, x[a] & x[b] );
			}
		}
	
	}else if ( m==3 ) {
		
		for ( a=0; a<n-2; a++ ) {
			for ( b=a+1; b<n-1; b++ ) {
				for ( c=b+1; c<n; c++ ) {
					MAX=max( MAX, x[a] & x[b] & x[c] );
				}
			}
		}
		
	}else if ( m==4) {
		
		for ( a=0; a<n-3; a++ ) {
			for ( b=a+1; b<n-2; b++ ) {
				for ( c=b+1; c<n-1; c++ ) {
					for ( d=c+1; d<n; d++ ) {
						MAX=max( MAX, x[a] & x[b] & x[c] & x[d] );
					}
				}
			}
		}
		
	}else if ( m==5 ) {
		
		for ( a=0; a<n-4; a++ ) {
			for ( b=a+1; b<n-3; b++ ) {
				for ( c=b+1; c<n-2; c++ ) {
					for ( d=c+1; d<n-1; d++ ) {
						for ( e=d+1; e<n; e++ ) {
							MAX=max( MAX, x[a] & x[b] & x[c] & x[d] & x[e] );
						}
					}
				}
			}
		}
		
	}else if ( m==6 ) {
		
		for ( a=0; a<n-5; a++ ) {
			for ( b=a+1; b<n-4; b++ ) {
				for ( c=b+1; c<n-3; c++ ) {
					for ( d=c+1; d<n-2; d++ ) {
						for ( e=d+1; e<n-1; e++ ) {
							for ( f=e+1; f<n; f++ ) {
								MAX=max( MAX, x[a] & x[b] & x[c] & x[d] & x[e] & x[f] );
							}
						}
					}
				}
			}
		}
		
	}
	cout<< MAX ;
	
 return 0;
 }
