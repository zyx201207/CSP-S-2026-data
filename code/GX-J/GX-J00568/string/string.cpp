#include<bits/stdc++.h>
using namespace std;
int n ;
int a[200005];
char c[200005];
long long num = 0;
int main()
{
    freopen( "string .in" , "r" , stdin );
    freopen ( "string.out" , "w" , stdout );
    cin >> n;
    if ( n == 1 )
    {
        cout << 0;
        return 0;
    }
    for ( int i = 1 ; i <= n ;i++ )
    {
        cin >>  a[i] >> c[i];
    }
    if ( n == 2 )
    {
        if ( c[1] != c[2] )
        {
            if( a[1] >= a[2] )
            {
                num = a[2];
            }
            else
            {
                num = a[1];
            }
        }
    }
    cout << num ;
    return 0;
}
