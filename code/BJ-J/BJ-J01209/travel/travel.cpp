#include<bits/stdc++.h>
using namespace std ;

long long x,y ;
string s1,s2,s3,s4 ;

int main()
{
    freopen( "travel.in","r",stdin ) ;
    freopen( "travel.out","w",stdout ) ;
    cin >> x >> s1 >> y >> s2 ;
    if( x==y )
    {
        cout << "1" ;
    }
    else
    {
        cout << "0000" ;
        return 0 ;
    }
    s3=s1.substr( 0,2 ) ;
    s4=s2.substr( 0,2 ) ;
    if( s3==s4 )
    {
        cout << "1" ;
    }
    else
    {
        cout << "000" ;
        return 0 ;
    }
    char a=s1[2] ;
    char b=s2[2] ;
    if( ( ( a>='A' && a<='C' ) && ( b>='A' && b<='C' ) ) || ( ( a>='D' && a<='F' ) && ( b>='D' && b<='F' ) ) )
    {
        cout << "1" ;
    }
    else
    {
        cout << "00" ;
        return 0 ;
    }
    if( ( a>='A' && a<='C' ) && ( b>='A' && b<='C' ) )
    {
        if( abs( a-b )==1 )
        {
            cout << 1 ;
        }
        else
        {
            cout << 0 ;
        }
    }
    else
    {
        cout << 1 ;
    }
    return 0 ;
}
