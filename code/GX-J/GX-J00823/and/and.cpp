#include <bits/stdc++.h>
using namespace std;
int n, m,a[200005], mx,book[200005],t[4];
void dfs(int t, int lj)
{
    if ( t == m )
    {
        mx = max(mx,lj) ;
        return ;
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( book[i] == 0 )
        {
            book[i] = 1 ;
            int c ;
            if ( lj == 0 )
            {
                c = a[i] ;
            }
            else
                c = lj & a[i] ;
            dfs(t + 1,c);
            book[i] = 0 ;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin >> a[i] ;
        mx = max(mx, a[i]);
    }
    if ( m == 1 )
    {
        cout << mx ;
        return 0 ;
    }
    if ( m == 2 )
    {
        mx = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            for ( int j = i+1 ; j <= n ; j++ )
            {
                mx = max(mx,(a[i]&a[j]));
            }
        }
        cout << mx ;
        return 0 ;
    }
    if ( mx < 4 )
    {
        for ( int i = 1 ; i <= n ; i++ )
        {
            t[a[i]]++ ;
        }
        if ( m <= t[3] ) {
            cout << 3 ;
            return 0 ;
        }
        m -= t[3] ;
        if ( m <= t[2] ) {
            cout << 2 ;
            return 0 ;
        }
        if ( m <= t[1] ) {
            cout << 1 ;
            return 0 ;
        }
        cout << 0 ;
    }
    mx = 0 ;
    dfs(0,0);
    cout << mx ;
    return 0;
}
