#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    long long num;
    char ch;
};
long long n, sum = 0;
bool v1 = 1, v2 = 1, v3 = 1;
int main()
{
    freopen( "string.in", "r", stdin );
    freopen( "string.out", "w", stdout );
    vector < NODE > a;
    vector < long long > fr;
    cin >> n;
    a.resize( n + 5 );
    fr.resize( n + 5 );
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i].num >> a[i].ch;
        sum += a[i].num;
        fr[i] = fr[i - 1] + a[i].num;
        if( i != 1 && a[i].ch != a[i-1].ch )
        {
            v1 = 0;
        }
        if( i != 1 && a[i].num != a[i-1].num )
        {
            v2 = 0;
        }
    }
    if( v1 == 1 )
    {
        cout << 0;
        return 0;
    }
    if( v2 == 1 )
    {
        for( int i = 1; i <= n / 2; i++ )
        {
            if( a[i].ch != a[n - i].ch )
            {
                v3 = 0;
            }
        }
        if( v3 == 1 )
        {
            cout << 0;
            return 0;
        }
    }
    cout << sum / 2;
    return 0;
}
