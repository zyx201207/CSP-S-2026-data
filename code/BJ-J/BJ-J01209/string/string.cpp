#include<bits/stdc++.h>
using namespace std ;

string s,s1,s2,s3 ;
long long n,cnt ;

int main()
{
    freopen( "string.in","r",stdin ) ;
    freopen( "string.out","w",stdout ) ;
    cin >> n ;
    for( int i=1 ; i<=n ; i++ )
    {
        int x ;
        char a ;
        cin >> x >> a ;
        for( int j=1 ; j<=x ; j++ )
        {
            s+=a ;
        }
    }
    int len=s.length() ;
    if( len%2==0 )
    {
        s1=s.substr( 0,len/2 ) ;
        s3=s.substr( len/2,len/2 ) ;
    }
    else
    {
        s1=s.substr( 0,len/2 ) ;
        s3=s.substr( len/2+1,len/2 ) ;
    }
    int len1=s1.length() ;
    for( int i=0 ; i<len1 ; i++ )
    {
        char a=s3[len1-1-i] ;
        s2+=a ;
    }
    for( int i=0 ; i<len1 ; i++ )
    {
        if( s1[i]!=s2[i] )
        {
            cnt++ ;
            s2[i]=s1[i] ;
        }
        if( s1==s2 )
        {
            break ;
        }
    }
    cout << cnt ;
    return 0 ;
}
