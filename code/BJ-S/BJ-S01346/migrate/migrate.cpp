#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int c, t, n, m, a[N], ans, num, l, s[N], cnt, minn = N, f[N], f_1;
int Mun( int p )
{
    l = p;
    while ( num <= m )
    {
        num += s[l++];
        cnt++;
    }
    return --cnt;

}
void Fun ( int p )
{

    if ( p > n )
    {

        return ;
    }
    ans++;
    cnt = Mun(p);
    for ( int i = 1; i <= cnt; i++ )
    {
        Fun( p + i );
        f[++f_1] = ans;
    }
}
int main()
{
    freopen( "migrate.in", "r", stdin );
    freopen( "migrate.out", "w", stdout );
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cin >> c >> t;
    for ( int a_1 = 1; a_1 <= t; a_1++ )
    {
        cin >> n >> m;
        for ( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            s[i] = abs( a[i] - a[i - 1] );
        }
        Fun( 1 );
        sort( f + 1, f + f_1 + 1 );
        int istv = 1;
        while ( f[istv] == f[istv + 1] )
        {
            istv++;
        }
        cout << istv - 1 << '\n';
    }
    return 0;
}