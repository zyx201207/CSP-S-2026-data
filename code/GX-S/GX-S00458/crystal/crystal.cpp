#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500001] , ans , b[500001] , s[500001] ;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i] ;
    }
    sort( a+1 , a+1+n ) ;
    for ( int i = 1 ; i <= n ; i ++)
    {
        s[i] = s[i-1] + (i-1)*(a[i]-a[i-1]) ;
    }
    for ( int i = n ; i > 1 ; i --)
    {
        if ( a[i] == a[i-1] )
        {
            b[i-1] = b[i]+1 ;
        }
    }
    for ( long long i = 1 ; i <= n ; i ++)
    {
        long long left = 0 , right = i , mid ;
        while(left<=right)
        {
            mid = (left+right)/2;
            long long d = s[i] - s[mid] - (a[i]-a[mid])*mid ;
            if ( d > m )
            {
                left = mid+1;
            }
            if ( d <= m )
            {
                right = mid-1;
            }
        }
        if ( i-left+b[i] > ans )
        {
            ans = i-left+b[i] ;
        }
    }
    cout << ans ;
    return 0;
}
