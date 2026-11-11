#include <bits/stdc++.h>
using namespace std ;
int n , d , cntmin , anscnt ;
int x[2000005] ;
void dfs ( int s , int t , int c , int cnt )
{
	if ( cnt > cntmin || c > t ) return ;
    if ( c == t )
    {
		if ( cnt < cntmin )
		{
			cntmin = cnt ;
			anscnt = 0 ;
		}
		anscnt ++ ;
	}
	if ( cnt == cntmin ) return ;
    for ( int i = c+1 ; i <= n && x[i]-x[c] <= d ; i ++ )
    {
        dfs(s,t,i,cnt+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c , t ;
    cin >> c >> t ;
    while ( t -- )
    {
        cin >> n >> d ;
        for ( int i = 1 ; i <= n ; i ++ ) cin >> x[i] ;
        int ans = 0 ;
        for ( int i = 1 ; i <= n ; i ++ )
        {
            for ( int j = i+1 ; j <= n ; j ++ )
            {
				anscnt = 0 ;
				cntmin = INT_MAX ;
				dfs(i,j,i,0);
                if ( anscnt == 2 ) ans ++ ;
            }
        }
        cout << ans << endl ;
    }
    return 0 ;
}

