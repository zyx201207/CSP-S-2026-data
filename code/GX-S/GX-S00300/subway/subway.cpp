#include <bits/stdc++.h>
using namespace std;
vector<int> v[500005] ;
int c, n, m, d, q, k, x, y, a[505][505], t[505][505], w[500005], book[500005], o[505], l[505][50005], mn ;
void dfs(int i,int sx,int tim)
{
    if ( i == y )
    {
        mn = min(tim + t[sx][l[sx][i]] , mn);
        return ;
    }
    for ( int j = 0 ; j < v[i].size() ; j++ )
    {
        if ( book[v[i][j]] == 0 )
        {
            if (sx == -1)
            {
                book[v[i][j]] = 1 ;
                dfs(v[i][j], o[v[i][j]], tim) ;
                book[v[i][j]] = 0 ;
                continue ;
            }
            if ( o[v[i][j]] == -1 || (sx == o[v[i][j]]))
            {
                book[v[i][j]] = 1 ;
                dfs(v[i][j], sx, tim) ;
                book[v[i][j]] = 0 ;
                continue ;
            }
            book[v[i][j]] = 1 ;
            dfs(v[i][j], o[v[i][j]], tim + t[sx][l[sx][i]] + t[o[v[i][j]]][l[o[v[i][j]]][v[i][j]]]) ;
            book[v[i][j]] = 0 ;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        cin >> w[i] ;
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin >> k ;
        for ( int j = 1 ; j <= k ; j++ )
        {
            cin >> a[i][j] >> t[i][j] ;
            l[i][a[i][j]] = j ;
            if ( j > 1 )
            {
                v[a[i][j]].push_back(a[i][j-1]);
                v[a[i][j-1]].push_back(a[i][j]);
            }
            if ( o[a[i][j]] != 0 )
            {
                o[a[i][j]] = -1 ;
            }
            else
                o[a[i][j]] = i ;
        }
    }
    for(int i = 1 ; i <= q ; i++ )
    {
        cin >> x >> y ;
        mn = 1000000000 ;
        book[x] = 1 ;
        dfs(x,o[x],0);
        book[x] = 0 ;
        cout << mn + w[x] + w[y] + t[o[x]][l[o[x]][x]] << '\n' ;
    }
    return 0;
}
