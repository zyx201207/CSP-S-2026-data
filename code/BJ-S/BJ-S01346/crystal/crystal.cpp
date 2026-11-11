#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int n, m, a[N], t[N], num, maxn, flag, b1, b2;
int main()
{
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cin >> n >> m;
    cin >> a[1] >> a[2];
    b1 = a[2] - a[1];
    for ( int i = 3; i <= n; i++ )
    {
        cin >> a[i];
        b2 = a[i] - a[i - 1];
        if ( b1 != b2 )
        {
            flag = true;
        }
    }
    if ( flag == false )
    {
        int cnt = 0, u = 0;
        while ( cnt <= m / abs( b1 - b2 ) )
        {
            cnt += ++u;

        }
        cout << --u << endl;
        return 0;
    }
    for ( int i = 1; i <= n; i++ )
    {
        num = a[i];
        for ( int j = 1; j <= n; j++ )
        {
            t[j] = abs( num - a[j] );


        }
        sort( a + 1, a + n + 1 );
        int ans = 0, s = 0;
        while ( ans <= m )
        {
            ans += t[++s];
        }
        s--;
        maxn = max( maxn, s );
    }
    cout << maxn << '\n';
    return 0;
}
