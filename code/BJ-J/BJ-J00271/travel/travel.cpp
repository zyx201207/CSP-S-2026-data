#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    freopen( "travel.in", "r", stdin );
    freopen( "travel.out", "w", stdout );
    cin >> c1 >> s1 >> c2 >> s2;
    if( c1 == c2 ) cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    int cnt1 = ( s1[0] - '0' ) * 10 + ( s1[1] - '0' ), cnt2 = ( s2[0] - '0' ) * 10 + ( s2[1] - '0' );
    char ch1 = s1[2], ch2 = s2[2];
    if( cnt1 == cnt2 ) cout << 1;
    else
    {
        cout << "000";
        return 0;
    }
    if( ( ch1 <= 'C' && ch2 <= 'C' ) || ( ch1 >= 'D' && ch2 >= 'D' ) ) cout << 1;
    else
    {
        cout << "00";
        return 0;
    }
    if( ch1 + 1 == ch2 || ch2 + 1 == ch1 ) cout << 1;
    else cout << 0;
    return 0;
}