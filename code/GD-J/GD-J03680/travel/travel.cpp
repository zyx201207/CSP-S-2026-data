#include <bits/stdc++.h>
using namespace std ;

int main ( ) {
    freopen ( "travel.in" , "r" , stdin ) ;
    freopen ( "travel.out" , "w" , stdout ) ;
    ios :: sync_with_stdio ( false ) ; cin . tie ( 0 ) ; cout . tie ( 0 ) ;
    string box1 , seat1 , box2 , seat2 ;
    cin >> box1 >> seat1 >> box2 >> seat2 ;
    char num1 = seat1 . back ( ) , num2 = seat2 . back ( ) ;
    seat1 . pop_back ( ) ; 
    seat2 . pop_back ( ) ;
    if ( num1 > num2 ) swap ( num1 , num2 ) ;
    if ( box1 != box2 ) cout << "0000" ;
    else {
        cout << '1' ;
        if ( seat1 != seat2 ) cout << "000" ;
        else {
            cout << '1' ;
            if ( num2 <= 'C' || num1 > 'C' ) {
                cout << '1' ;
                if ( num2 == num1 + 1 || num1 > 'C' ) cout << '1' ;
                else cout << '0' ;
            }
            else cout << "00" ;
        }
    }
    return 0 ;
}
