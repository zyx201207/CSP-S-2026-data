#include<bits/stdc++.h>
using namespace std ;
const int N=2147483647 ;
int n,m,maxx ;
long long a[200050] ;

void dfs( int pos,int sum,int num )
{
    if( num>=m )
    {
        maxx=max( sum,maxx ) ;
        return ;
    }
    if( pos>n )
    {
        return ;
    }
    dfs( pos+1,sum&a[pos],num+1 ) ;
    dfs( pos+1,sum,num ) ;
}
int main()
{
    freopen( "and.in","r",stdin ) ;
    freopen( "and.out","w",stdout ) ;
    cin >> n >> m ;
    for( int i=1 ; i<=n ; i++ )
    {
        cin >> a[i] ;
    }
    dfs( 1,N,0 ) ;
    cout << maxx ;
    return 0 ;
}
