#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010], A = 1, vis[200010], ans[200010], now;
struct Node
{
    int pre, nxt;
}lit[200010];
void OUTPUT()
{
    now = 0;
    do
    {
        cout << now << " ";
        now = lit[now].nxt;
    }
    while( now != 0 );
    cout << endl;
}
int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    freopen( "card2.in", "r", stdin );
    freopen( "card2.out", "w", stdout );
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        if( a[i] < a[i - 1] ) A = 0;
    }
    if( A )//16
    {
        for( int i = 2; i <= n; i++ )
        {
            if( a[i] != a[i - 1] ) cout << i - 1 << " ";
        }
        cout << n;
        return 0;
    }
    if( n <= 500 )//24
    {
        for( int i = 1; i <= n; i++ )
        {
            memset( lit, 0, sizeof( lit ) );
            memset( vis, 0, sizeof( vis ) );
            for( int j = i, pre = 0; j <= n; j++ )
            {
                if( vis[a[j]] )
                {
                    int nxt = lit[a[j]].nxt;
                    while( nxt != 0 )
                    {
                        lit[nxt].pre = 0, vis[nxt] = 0;
                        nxt = lit[nxt].nxt;
                    }
                }
                else lit[a[j]].pre = pre, lit[pre].nxt = a[j], vis[a[j]] = 1, pre = a[j];
                //OUTPUT();
            }
            now = 0;
            do
            {
                ans[now]++;
                now = lit[now].nxt;
            }
            while( now != 0 );
        }
        for( int i = 1; i <= m; i++ ) cout << ans[i] << " ";
        return 0;
    }
}
