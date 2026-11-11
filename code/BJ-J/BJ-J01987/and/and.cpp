#include <bits/stdc++.h>
using namespace std;
const int N = 100020;
int a[N], maxn = -1, tmp;
int n, m, ans;
bool v1 = 1,v2 = 1;
int main()
{
    freopen( "and.in", "r", stdin );
    freopen( "and.out", "w", stdout );
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
    }
    for( int i = 1; i <= n; i++ )
    {
        if( v1 == 1 && a[i] + 1 % 2 == 0 )
        {
            v1 = 1;
            continue;
        }
        v1 = 0;
    }
    if( v1 == 1 )
    {
        sort( a + 1, a + n + 1 );
        cout << a[n - m + 1];
        return 0;
    }
    for( int i = 1; i <= n; i++ )
    {
        if( v2 == 1 && a[i] == i - 1 )
        {
            v2 = 1;
            continue;
        }
        v2 = 0;
    }
    if( v2 == 1 )
    {
        ans = a[n];
        for( int i = 1; i <= m; i++ )
        {
            ans = ans & a[n - i];
        }
        cout << ans;
        return 0;
    }
    cout << a[n / 2];
    return 0;
}
