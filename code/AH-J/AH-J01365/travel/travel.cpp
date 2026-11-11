#include <bits/stdc++.h>
using namespace std ;

int main () {
    freopen ( "travel.in" , "r" , stdin ) ;
    freopen ( "travel.out" , "w" , stdout ) ;
    string c1 , s1 , c2 ,  s2 ;
    cin >> c1 >> s1 >> c2 >> s2 ;
    string temp1 = s1 , temp2 =s2 ;
    string s10 = s1.erase( 2 ,1 );
    string s20 = s2.erase( 2 ,1 );
    string s11 = temp1.erase( 0 ,2 );
    string s22 = temp2.erase( 0 ,2 );
    if ( c1 == c2 ) {
        cout << "1" ;
        if ( s10 == s20 ) {
            cout << "1" ;
            if ( ( s11 <= "C" && s22<= "C" ) ) {
        cout << "1" ;
        (( s11 =="B" && s22 == "C") || ( s11 =="C" && s22 == "B") || ( s11 =="A" && s22 == "B") || ( s11 =="B" && s22 == "A"))? cout << "1" : cout << "0" ;
    }
    else if ( s11 > "C" && s22 > "C" ) cout << "11" ;
    else cout << "00" ;
        }
        else cout << "000" ;
    }
    else cout << "0000" ;

    return 0 ;
}
