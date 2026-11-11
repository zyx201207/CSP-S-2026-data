#include<bits/stdc++.h>
using namespace std ;

const int N=500050 ;
long long n,m,a[N],cnt ;

int main()
{
    freopen( "crystal.in","r",stdin ) ;
    freopen( "crystal.out","w",stdout ) ;
    cin >> n >> m ;
    for( int i=1 ; i<=n ; i++ )
    {
        cin >> a[i] ;
    }
    for( int i=1 ; i<n ; i++ )
    {
        while( a[i]!=a[i+1] )
        {
            for( int j=1 ; j<=i ; j++ )
            {
               if( m!=0 )
               {
                   m--,a[j]++ ;
               }
               else
               {
                   for( int k=1 ; k<=n ; k++ )
                   {
                       if( a[k]==a[1] )
                       {
                           cnt++ ;
                       }
                   }
                   cout << cnt ;
                   return 0 ;
               }
            }
        }
    }
    for( int k=1 ; k<=n ; k++ )
    {
        if( a[k]==a[1] )
        {
            cnt++ ;
        }
    }
    cout << cnt ;
    return 0 ;
}
