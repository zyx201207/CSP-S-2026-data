#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10 ;
vector <int> g[maxn] ;
int c , t , n , x , y , s , k , pos[maxn] , fa[maxn] , d[maxn] , f[20][maxn] , ans ;
bool vis[maxn][maxn] ;
int find ( int x ){
    return x == fa[x] ? x : fa[x] = find(fa[x]) ;
}
void dfs2 ( int u ){
    for ( int i = 1 ; i < 20 ; i++ ) f[i][u] = f[i-1][f[i-1][u]] ;
    for ( auto v : g[u] ){
        if ( v == f[0][u] ) continue;
        f[0][v] = u ;
        d[v] = d[u] + 1 ;
        dfs2(v);
    }
}
int lca ( int x , int y ){
    if ( d[x] < d[y] ) swap(x,y);
    for ( int i = 19 ; i >= 0 ; i-- ){
        if ( d[f[i][x]] >= d[y] ){
            x = f[i][x] ;
        }
    }
    if ( x == y ) return x ;
    for ( int i = 19 ; i >= 0 ; i-- ){
        if ( f[i][x] != f[i][y] ){
            x = f[i][x] ;
            y = f[i][y] ;
        }
    }
    return f[0][x] ;
}
int calc (){
    for ( int i = 1 ; i <= k ; i++ ){
        fa[pos[i]] = pos[i] ;
    }
    s = k ;
    for ( int i = 1 ; i <= k ; i++ ){
        for ( int j = 1 ; j <= k ; j++ ){
            if ( !vis[pos[i]][pos[j]] ) continue;
            int x = find(pos[i]),  y = find(pos[j]) ;
            if ( x != y ){
                s--;
                fa[x] = y ;
            }
        }
    }
    if ( s > 2 ) return n + 1 ;
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++ ){
        int tmp = n + 1 ;
        for ( int j = 1 ; j <= k ; j++ ){
            tmp = min ( tmp , d[i] + d[pos[j]] - 2 * d[lca(i,pos[j])] ) ;
        }
        res = max ( res , tmp ) ;
    }
    return res ;
}
void dfs ( int u , int cnt ){
    if ( cnt == k ){
        ans = min ( ans , calc() ) ;
        return;
    }
    if ( u > n ) return;
    pos[cnt+1] = u ;
    dfs(u+1,cnt+1);
    dfs(u+1,cnt);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while ( t-- ){
        scanf("%d%d",&n,&k);
        memset(vis,0,sizeof(vis));
        for ( int i = 1 ; i <= n ; i++ ) g[i].clear();
        d[1] = 1 ;
        for ( int i = 1 ; i < n ; i++ ){
            scanf("%d%d",&x,&y);
            vis[x][y] = vis[y][x] = 1 ;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs2(1);
        ans = n + 1 ;
        if ( c <= 3 || c == 7 ){
            dfs(1,0);
            printf("%d\n",ans);
        }
    }
    return 0 ;
}
