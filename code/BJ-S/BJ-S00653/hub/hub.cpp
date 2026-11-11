#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen( "hub.in" , "r" , stdin );
    freopen( "hub.out" , "w" , stdout );
    int c , t;
    cin >> c >> t;
    while( t -- ) {
        cin >> n >> k;
        if ( n == k )  cout << 0;
        else if ( k >= ( n / 2 ) )
            cout << 1;
        else
            cout << n / k - 1;
        cout << endl;
    }
}