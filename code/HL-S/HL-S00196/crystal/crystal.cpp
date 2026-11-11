#include <bits/stdc++.h>
using namespace std ;
#define int long long
int n , m ;
int a[500005] ;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        cin >> a[i] ;
    }
    sort(a+1,a+n+1);
    int ans = 0 , sum = 0 ;
    int left = 1 , right = 1 ;
    while ( right != n+1 )
    {
        while ( left != right && sum > m )
        {
            sum -= a[right]-a[left] ;
            left ++ ;
        }
        int cnt = right-left+1 ;
        ans = max(ans,cnt);
        sum += cnt*(a[right+1]-a[right]);
        right ++ ;
    }
    cout << ans ;
    return 0 ;
}
