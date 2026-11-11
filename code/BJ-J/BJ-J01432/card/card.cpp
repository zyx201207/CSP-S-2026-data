#include<bits/stdc++.h>
using namespace std;
int n, m, maxn, num;
const int N = 5005;
int a[N], d[N], t[N];
int main()
{
    freopen( "card.in", "r", stdin );
    freopen( "card.out", "w", stdout );
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        maxn = max( maxn, a[i] );
    }
    for ( int i = 1; i <= n; i++ )
    {
        num = 0;
        for ( int j = i; j <= n; j++ )
        {

            bool flag = false;
            for ( int k = 1; k <= num; k++ )
            {
                if ( d[k] == a[j] )
                {
                    flag = true;
                    break;
                }

            }
            if ( flag == true )
            {
                for ( int k = 1; k <= num; k++ )
                {
                    d[k] = 0;
                }
                num = 0;
            }
            d[++num] = a[j];
        }
        for ( int j = 1; j <= num; j++ )
        {
            t[d[j]]++;

        }

    }
    for ( int i = 1; i <= maxn; i++ )
    {
        cout << t[i] << ' ';

    }
    return 0;
}
