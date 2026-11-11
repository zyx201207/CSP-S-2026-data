#include <bits/stdc++.h>
using namespace std ;
int a[1000000005] ;
string si,S ;

int main () {
    freopen ( "string.in" , "r" , stdin ) ;
    freopen ( "string.out" , "w" , stdout ) ;
    int n ; cin >> n ;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a[i] ;
        cin >> si[i] ;
        for ( int i = 0 ; i < a[i] ; i++ ) S.append( si[i] );
    }

    return 0 ;
}

