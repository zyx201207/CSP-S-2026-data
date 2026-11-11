#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen( "travel.in" , "r" , stdin );
    freopen( "travel.out" , "w" , stdout );
    string c1 , c2 , s1 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if ( c1 == c2 ) {
        cout << "1";
        if ( s1[0] == s2[0] && s1[1] == s2[1] ) {
            cout << "1";
            char x , y;
            x = s1[2] , y = s2[2];
            int xx , yy;
            if ( x == 'A' || x == 'B' || x == 'C' ){
                xx = 1;
            }
            else
                xx = 0;
            if ( y == 'A' || y == 'B' || y == 'C' )
                yy = 1;
            else
                yy = 0;
            if ( xx == yy ) {
                cout << "1";
                if ( ( x == 'A' && y == 'C' ) || ( x == 'C' && y == 'A' ) )
                    cout <<"0";
                else
                    cout << "1";
            }
            else{
                cout <<"00";
            }
        }
        else {
            cout << "000";
        }

    }
    else {
        cout << "0000";
    }
}
