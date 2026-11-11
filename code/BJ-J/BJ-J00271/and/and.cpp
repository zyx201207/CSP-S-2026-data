#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200010], vis[200010], maxn = 1, ans;
void dfs( int step, int cnt )
{
    if( cnt > m ) return ;
    if( step > n && cnt == m )
    {
        long long num = maxn;
        for( int i = 1; i <= n; i++ ) if( vis[i] ) num &= a[i];
        ans = max( ans, num );
        return ;
    }
    if( step > n ) return ;
    vis[step] = 1;
    dfs( step + 1, cnt + 1 );
    vis[step] = 0;
    dfs( step + 1, cnt );
}
int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    freopen( "and.in", "r", stdin );
    freopen( "and.out", "w", stdout );
    for( int i = 1; i <= 32; i++ ) maxn *= 2;
    maxn--;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ ) cin >> a[i];
    if( n <= 20 )//25
    {
        dfs( 1, 0 );
        cout << ans;
        return 0;
    }
    if( m == 1 )//5
    {
        sort( a + 1, a + n + 1 );
        cout << a[n];
    }
}
