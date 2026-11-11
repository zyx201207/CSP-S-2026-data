#include<bits/stdc++.h>
using namespace std;
int n, m, maxn, num;
const int N = 1e5 + 5;
int a[N];
int main()
{
    freopen( "and.in", "r", stdin );
    freopen( "and.out", "w", stdout );
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
    }
    if ( m == 1 )
    {
        for ( int i = 1; i <= n; i++ )
        {
            maxn = max( maxn, a[i] );
        }
    }
    if ( m == 2 )
    {
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = i + 1; j <= n; j++ )
            {
                    num = a[i] & a[j];
                    maxn = max( maxn, num );
            }
        }
    }
    cout << maxn;
    return 0;
}
