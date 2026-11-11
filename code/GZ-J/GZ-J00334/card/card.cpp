//GZ-J00334贵阳市第十六中学曾楠博
#include <bits/stdc++.h>
int n, m, a[500005], b[500005], c[300005];
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        b[i] = a[i];
    }
    for( int i = 1; i <= m; i++ )
    {
        for( int j = i; j <= n; j++ )
        {
            for( int x = 1; x <= j; x++ )
            {
                if( b[x] == b[j] )
                {
                    for( int y = x; y <= j; y++ )
                    {
                        b[y] = 0;
                    }
                }
            }
        }
        for( int j = 1; j <= n; j++ )
        {
            if( b[j] != 0 )
            {
                c[b[j]]++;
                break;
            }
            b[j] = a[j];
        }
    }
    for( int i = 1; i <= m; i++ )
    {
        cout << c[i] << " ";
    }
    return 0;
}
