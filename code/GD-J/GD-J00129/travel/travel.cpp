#include <bits/stdc++.h>
using namespace std ;
string c1 ,s1 ,c2 ,s2 ,ts1 , ts2 ;
int main ( ) {

    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;

    ios::sync_with_stdio(0);
    cin.tie(0) ;

    cin >> c1 >> s1 >> c2 >> s2 ;
    if (c1 != c2) {
        cout << "0000" ;
        return 0 ;
    }

    ts1 = s1 , ts2 = s2 ;

    ts1.pop_back() ;
    ts2.pop_back() ;

    if (ts1 != ts2) {
        cout << "1000" ;
        return 0 ;
    }

    char t1 = s1[s1.size()-1] , t2 = s2[s2.size()-1] ;
    
    if (!(t1 >= 'D' && t2 >='D' || t1 <= 'C' && t2 <= 'C')) {
        cout << "1100" ;
        return 0 ;
    }

    if (abs(t1-t2) != 1) {
        cout << "1110" ;
        return 0 ;
    }

    cout << "1111" ;

    return 0 ;
}