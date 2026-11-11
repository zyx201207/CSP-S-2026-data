#include <bits/stdc++.h>
using namespace std;
int c1,c3;
string c2, c4, t1, t2;
char m1, m2;
int main()
{
    freopen( "travel.in", "r", stdin );
    freopen( "travel.out", "w", stdout );
    cin >> c1 >> c2 >> c3 >> c4;
    if( c1 != c3 )
    {
        cout << "0000" << endl;
        return 0;
    }
    for( int i = 0; i < 2; i++ )
    {
        t1 += c2[i];
        t2 += c4[i];
    }
    if( t1 != t2 )
    {
        cout << "1000" << endl;
        return 0;
    }
    m1 = c2[2], m2 = c4[2];
    if( (m1 <= 'C' && m2 > 'C') || (m1 > 'C' && m2 <= 'C') )
    {
        cout << "1100" << endl;
        return 0;
    }
    if( m1 + 1 != m2  && m2 + 1 != m1 )
    {
        cout << "1110" << endl;
        return 0;
    }
    cout << "1111" << endl;
    return 0;
}