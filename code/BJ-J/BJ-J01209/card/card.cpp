#include<bits/stdc++.h>
using namespace std ;

const int N=100050 ;
long long a[N],n,m,sum[N],b[N] ;

int main()
{
    freopen( "card.in","r",stdin ) ;
    freopen( "card.out","w",stdout ) ;
    cin >> n >> m ;
    for( int i=1 ; i<=n ; i++ )
    {
        cin >> a[i] ;
    }
    for( int i=1 ; i<=n ; i++ )
    {
        int k=i ;
        for( int j=i ; j<=n ; j++,k++ )
        {
            int ij ;
            bool flag=true ;
            for( int l=i ; l<j ; l++ )
            {
                if( a[j]==b[l] )
                {
                    ij=l ;
                    flag=false ;
                    break ;
                }
            }
            for( int l=i ; l<k ; l++ )
            {
                cout << b[l] << " " ;
            }
            cout << endl ;
            if( flag )
            {
                b[k]=a[j] ;
            }
            else
            {
                k=ij ;
            }
        }
        for( int j=i ; j<k ; j++ )
        {
            cout << b[j] << " " ;
            sum[b[j]]++ ;
        }
        cout << endl ;
    }
    for( int i=1 ; i<=m ; i++ )
    {
        cout << sum[i] << " " ;
    }
    return 0 ;
}
