#include<bits/stdc++.h>
using namespace std ;

const int N=2000005 ;
int c,t,n,d,a[N],minx,cnt,ans ;

void dfs( int x,int y,int b,int l )
{
    if( b==y )
    {
        if( l<minx )
        {
            minx=l,cnt=0 ;
        }
        else if( l==minx )
        {
            cnt++ ;
        }
        return ;
    }
    int i=1 ;
    while( 1 )
    {
        if( a[b+i]-a[b]>d || b+i>y )
        {
            break ;
        }
        dfs( x,y,b+i,l+1 ) ;
        i++ ;
    }
}

bool check( int x,int y )
{
    minx=1e9,cnt=0 ;
    dfs( x,y,x,0 ) ;
    if( cnt!=1 )
    {
        return false ;
    }
    else
    {
        return true ;
    }
}

int main()
{
    freopen( "migrate.in","r",stdin ) ;
    freopen( "migrate.out","w",stdout ) ;
    cin >> c >> t ;
    for( int i=1 ; i<=t ; i++ )
    {
        ans=0 ;
        cin >> n >> d ;
        for( int i=1 ; i<=n ; i++ )
        {
            cin >> a[i] ;
        }
        for( int i=1 ; i<=n ; i++ )
        {
            for( int j=i+3 ; j<=n ; j++ )
            {
                if( check( i,j ) )
                {
                    ans++ ;
                }
            }
        }
        cout << ans << endl ;
    }
    return 0 ;
}