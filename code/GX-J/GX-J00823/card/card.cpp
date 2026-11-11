#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], book[500005], ans[500005] ;
int main()
{
   freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin >> a[i] ;
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        int bi = 0 ;
        memset(b,0,sizeof(b));
        memset(book,0,sizeof(book));
        for ( int j = i ; j <= n ; j++ )
        {
            if ( book[a[j]] == 0 )
            {
                b[++bi] = a[j] ;
                book[a[j]] = bi ;
            }
            else
            {
                for ( int k = bi ; k > book[a[j]] ; k-- )
                    book[b[k]] = 0 ;
                bi = book[a[j]] ;
            }
        }
        for ( int j = 1 ; j <= bi ; j++ ) {
            ans[b[j]]++ ;
        }
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        cout << ans[i] << ' ' ;
    }
    return 0;
}
