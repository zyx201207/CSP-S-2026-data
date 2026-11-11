#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 510 ;
const int maxm = 5e5 + 10 ;
vector <pair<int,int>> fr[maxm] , se[maxm] , g[maxn] ;
int c , n , m , d , p , w[maxm] , k , x , y ;
ll dis[maxn][maxn] , ans ;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
    for ( int i = 1 ; i <= m ; i++ ){
        scanf("%d",&w[i]);
    }
    for ( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&k);
        for ( int j = 1 ; j <= k ; j++ ){
            scanf("%d%d",&x,&y);
            se[x].push_back({i,y});
            fr[i].push_back({x,y});
        }
    }
    for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = 1 ; j <= n ; j++ ){
            if ( i != j ) dis[i][j] = 1e15 ;
        }
    }
    for ( int i = 1 ; i <= n ; i++ ){
        for ( auto it : fr[i] ){
            x = it.first ;
            int len = it.second ;
            for ( auto it2 : se[x] ){
                int v = it2.first , len2 = it2.second ;
                if ( v == i ) continue;
                dis[i][v] = min ( dis[i][v] , 1ll * len + 1ll * len2 ) ;
            }
        }
    }
    for ( int k = 1 ; k <= n ; k++ ){
        for ( int i = 1 ; i <= n ; i++ ){
            for ( int j = 1 ; j <= n ; j++ ){
                dis[i][j] = min ( dis[i][j] , dis[i][k] + dis[k][j] ) ;
            }
        }
    }
    while ( p-- ){
        scanf("%d%d",&x,&y);
        ans = 1e15 ;
        for ( auto it : se[x] ){
            int u = it.first , len = it.second ;
            for ( auto it2 : se[y] ){
                int v = it2.first , len2 = it2.second ;
                ans = min ( ans , dis[u][v] + 1ll * w[u] + 1ll * w[v] + 1ll * len + 1ll * len2 ) ;
            }
        }
        printf("%lld\n",ans);
    }
    return 0 ;
}
