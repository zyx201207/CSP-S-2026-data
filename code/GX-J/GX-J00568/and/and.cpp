#include<bits/stdc++.h>
using namespace std;
int n  , m;
int a[200005];
long long maxn = -1;
long long num = -1;
int main()
{
    freopen( "and.in" , "r" , stdin );
    freopen ( "and.out" , "w" , stdout );
    cin >> n >> m;
    for ( int i = 1 ; i <= n ;i++ )
    {
        cin >> a[i];
    }
    if ( m == 1 )
    {
        sort ( a + 1 , a + n +1 );
        cout << a[n];
        return 0;
    }
    bool w = 1;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( a[i] != a[i + 1] )
        {
            w = 0;
        }
    }
    if ( w == 1 )
    {
        cout << a[1];
        return 0;
    }
}
