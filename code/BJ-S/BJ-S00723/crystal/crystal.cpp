#include <bits/stdc++.h>
using namespace std ;
#define int long long
int n , m ;
int a[500010] , sa[500010];

bool check(int x)
{
    int minn = 1e18 ; 
    for(int i = x ; i <= n ; i ++)
        minn = min(minn , (x - 1) * a[i] - (sa[i - 1] - sa[i - x])) ;

    return minn <= m ;
}
signed main()
{
    freopen("crystal.in" , "r" , stdin) ;
    freopen("crystal.out" , "w" , stdout) ;

    ios::sync_with_stdio(0) ;
    cin.tie(0) , cout.tie(0) ;
    cin >> n >> m ; 

    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ;
 
    sort(a + 1 , a + n + 1) ;
    for(int i = 1 ; i <= n ; i ++)
        sa[i] = sa[i - 1] + a[i] ;
    
    int l , r , ans = 0 ;
    l = 1 , r = n ;

    while(l <= r)
    {
        int mid = l + r >> 1 ;
        if(check(mid))
            ans = mid , l = mid + 1 ;
        else
            r = mid - 1 ;  
    }

    cout << ans << endl; 
    return 0 ;
}