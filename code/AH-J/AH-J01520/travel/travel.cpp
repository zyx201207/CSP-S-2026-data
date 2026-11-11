#include<bits/stdc++.h>
using namespace std;

struct node
{
    string s;
    string c;

    node ()
    {
        s = c = "";
    }
};
node x , r;

int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );

    freopen( "travel.in" , "r" , stdin );
    freopen( "travel.out" , "w" , stdout );

    cin >> x.s >> x.c >> r.s >> r.c;

    if ( x.s == r.s )
    {
        cout << 1 ;

        if ( x.c [ 0 ] + x.c [ 1 ] == r.c [ 0 ] + r.c [ 1 ] )
        {
            cout << 1 ;

            if ( 'A' <= x.c [ 2 ] && x.c [ 2 ] <= 'C' && 'A' <= r.c [ 2 ] && r.c [ 2 ] <= 'C' )
            {
                cout << 1 ;

                if ( 'A' == x.c [ 2 ] && 'B' == r.c [ 2 ] ) cout << 1 ;
                else if ( 'B' == x.c [ 2 ] && 'A' == r.c [ 2 ] ) cout << 1 ;
                else if ( 'B' == x.c [ 2 ] && 'C' == r.c [ 2 ] ) cout << 1 ;
                else if ( 'C' == x.c [ 2 ] && 'B' == r.c [ 2 ] ) cout << 1 ;
                else cout << 0 ;
            }
            else if ( 'D' <= x.c [ 2 ] && x.c [ 2 ] <= 'F' && 'D' <= r.c [ 2 ] && r.c [ 2 ] <= 'F' )
            {
                cout << 1 ;

                if ( 'D' == x.c [ 2 ] && 'F' == r.c [ 2 ] ) cout << 1 ;
                else if ( 'F' == x.c [ 2 ] && 'D' == r.c [ 2 ] ) cout << 1 ;
                else cout << 0 ;
            }
            else
            {
                cout << "00" ;
            }
        }
        else
        {
            cout << "000" ;
        }
    }
    else
    {
        cout << "0000" ;
    }

    return 0 ;
}
