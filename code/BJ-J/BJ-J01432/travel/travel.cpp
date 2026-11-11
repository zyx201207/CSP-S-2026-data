#include<bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int n, m, p, q;

int main()
{
    freopen( "travel.in", "r", stdin );
    freopen( "travel.out", "w", stdout );
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cin >> c1 >> s1 >> c2 >> s2;
    if ( c1 == c2 )
    {
        cout << 1;
        n = 1;
    }
    else
    {
        cout << 0;
        n = 0;
    }
    if ( s1[0] == s2[0] && s1[1] == s2[1] )
    {
        cout << 1;
        m = 1;
    }
    else
    {
        cout << 0;
        m = 0;
    }
    if ( n == 1 && m == 1 )
    {
        if ( ( s1[2] == 'A' ||  s1[2] == 'B' ||  s1[2] == 'C' && s2[2] == 'A' ||  s2[2] == 'B' ||  s2[2] == 'C' ) || ( s1[2] == 'D' ||  s1[2] == 'E' && s2[2] == 'D' ||  s2[2] == 'E' ) )
        {
            cout << 1;
            p = 1;
        }
        else
        {
            cout << 0;
            p = 0;
        }
    }
    if ( p == 1 )
    {
        if ( s1[2] == 'D' || ( s1[2] == 'A' && s2[2] == 'B' ) || ( s1[2] == 'B' && s2[2] == 'C' ) || ( s2[2] == 'A' && s1[2] == 'B' ) || ( s2[2] == 'B' && s1[2] == 'C' ))
        {
            cout << 1;
        }
        else
        {

            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    return 0;
}
