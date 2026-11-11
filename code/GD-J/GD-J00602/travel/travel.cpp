#include<bits/stdc++.h>

using namespace std;
string x, y, xx, yy;
int ans[10];
void slove(){
    cin >> x >> xx >> y >> yy;
    if( x != y ){
        cout << "0000";
    } else{
        cout << 1;
        if( xx[0] == yy[0] && xx[1] == yy[1] ){
            cout << 1;
            if( ( xx[2] == 'A' && yy[2] == 'C' ) || ( xx[2] == 'C' && yy[2] == 'A' ) ){
                cout << "10";
            } else if( ( xx[2] == 'D' && yy[2] == 'C' ) || ( xx[2] == 'C' && yy[2] == 'D' ) ){
                cout << "00";
            } else if( abs(( int )( xx[2] - yy[2] )) == 1 ){
                cout << "11";
            } else cout << "00";
        } else cout << "000";
    }

    return;
}

int main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "travel.in", "r", stdin );
    freopen( "travel.out", "w", stdout );
    int T = 1;
    // cin >> T;
    while( T -- )
        slove();
    return 0;
}