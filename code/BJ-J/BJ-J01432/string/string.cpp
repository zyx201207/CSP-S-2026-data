#include<bits/stdc++.h>
using namespace std;
int n, len, a, k, ans;
string s, b;
int main()
{
    freopen( "string.in", "r", stdin );
    freopen( "string.out", "w", stdout );
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> a >> b;
        for ( int j = 1; j <= a; j++ )
        {
            s += b;
            len++;
        }
    }
    k = len / 2;

    for ( int i = 0; i <= k; i++ )
    {
        if ( s[i] != s[len - i - 1] )
        {
            ans++;
        }

    }
    cout << ans;
    return 0;
}
