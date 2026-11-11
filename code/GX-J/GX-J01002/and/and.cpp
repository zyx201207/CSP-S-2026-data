#include<bits/stdc++.h>
using namespace std ;
long long n , m , a[222222] , sum ;
string s[222222] , t ;
string zh(long long x)
{
    int ans=0 ;
    string y="" ;
    while (x)
    {
        ans++ ;
        y=(x%2+'0')(char)+y ;
    }
    for (int i=1 ; i<=31-ans ; i++)
        y='0'+y ;
}
string zh2
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout) ;
    cin >> n >> m ;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i] ;
        s[i]=zh(a[i]) ;
    }
    sort(s+1 , s+n+1) ;
    for (int i=30 ; i>=0 ; i++)
    {
        t=
    }
    return 0 ;
}
