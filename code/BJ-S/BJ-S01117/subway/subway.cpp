#include<bits/stdc++.h>
using namespace std ;

const int N=500050 ;
int c,n,m,d,q ;
int w[N],a[505][N],t[505][N],k,x,y ;
vector< int > e[N] ;

int main()
{
    freopen( "subway.in","r",stdin ) ;
    freopen( "subway.out","w",stdout ) ;
    cin >> c >> n >> m >> d >> q ;
    for( int i=1 ; i<=m ; i++ )
    {
        cin >> w[i] ;
    }
    for( int i=1 ; i<=n ; i++ )
    {
        cin >> k ;
        for( int j=1 ; j<=k ; j++ )
        {
            cin >> a[i][j] >> t[i][j] ;
            for( int l=1 ; l<=j ; l++ )
            {
                e[a[i][j]][a[i][l]]=min( e[a[i][j]][a[i][l]],t[i][j]+t[i][l] ) ;
            }
        }
    }
    for( int i=1 ; i<=q ; i++ )
    {
        cin >> x >> y ;
        cout << w[x]+w[y]+e[x][y] << endl ;
    }
    return 0 ;
}
