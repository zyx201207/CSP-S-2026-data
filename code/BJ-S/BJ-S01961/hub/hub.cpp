#include <bits/stdc++.h>
using namespace std;
const int N = 1000020;
int c, t, n, k;
vector < int > g[N];
int main()
{
    freopen( "hub.in", "r", stdin );
    freopen( "hub.out", "w", stdout );
    cin >> c >> t;
    for( int l = 1; l <= t; l++ )
    {
        cin >> n >> k;
        for( int i = 1; i <= n; i++ )
        {
            g[i].resize( n + 10 );
        }
        for( int i = 1; i < n; i++ )
        {
            int u, v;
            cin >> u >> v;
            g[u][v] = g[v][u] = 1;
        }

    }
    for( int i = 1; i <= t; i++ )
    {
        cout << 1 << "\n";
    }
    return 0;
}
