#include <bits/stdc++.h>
using namespace std;
long long n, ans;
struct Node
{
    long long x;
    char ch;
}a[200010];
int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    freopen( "string.in", "r", stdin );
    freopen( "string.out", "w", stdout );
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> a[i].x >> a[i].ch;
    for( int i = 1, j = n; i <= j; )
    {
        if( a[i].ch != a[j].ch ) ans += min( a[i].x, a[j].x );
        if( a[i].x > a[j].x ) a[i].x -= a[j].x, j--;
        else if( a[i].x == a[j].x ) i++, j--;
        else a[j].x -= a[i].x, i++;
    }
    cout << ans;
    return 0;
}
