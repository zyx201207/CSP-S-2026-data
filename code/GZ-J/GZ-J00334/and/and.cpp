//GZ-J00334贵阳市第十六中学曾楠博
#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], sum;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
    }
    if( m == 1 )
    {
        int max = 0;
        for( int i = 1; i <= n; i++ )
        {
            if( max < a[i] ) max = a[i];
        }
        cout << max;
    }
    else if( m == n )
    {
        sum = a[1];
        for( int i = 2; i <= n; i++ )
        {
            sum = (sum & a[i]);
        }
        cout << sum;
    }
    else if( m == 2 )
    {
        for( int i = 1; i <= n; i++ )
        {
            for( int j = i + 1; j <= n; j++ )
            {
                if( ( a[i] & a[j] ) > sum ) sum = (a[i] & a[j]);
            }
        }
        cout << sum;
    }
    else if( m == n - 1 )
    {
        for( int i = 1; i <= n; i++ )
        {
            int h;
            if( i == 1 ) h = a[2];
            else h = a[1];
            if( i == 1 ) for( int j = 3; j <= n; j++ )
            {
                h = ( h & a[i] );
            }
            else  for( int j = 1; j <= n; j++ )
            {
                if( j != i )h = ( h & a[i] );
            }
            if( h > sum ) sum = h;
        }
        cout << sum;
    }
    return 0;
}
