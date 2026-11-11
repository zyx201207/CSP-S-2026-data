#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10 ;
vector <int> g[maxn] ;
ll val[maxn] , d , ans ;
int c , t , n , dis[maxn] , vis[maxn] , q[maxn] , l , r ;
ll cnt[maxn] ;
void bfs ( int st ){
    for ( int i = 1 ; i <= n ; i++ ){
        dis[i] = n + 1 ;
        vis[i] = 0 ;
        cnt[i] = 0 ;
    }
    q[1] = st ;
    l = r = 1 ;
    cnt[st] = 1 ;
    dis[st] = 0 ;
    while ( l <= r ){
        int u = q[l] ;
        l++;
        if ( vis[u] ) continue;
        vis[u] = 1 ;
        for ( auto v : g[u] ){
            if ( dis[v] > dis[u] + 1 ){
                dis[v] = dis[u] + 1 ;
                cnt[v] = cnt[u] ;
                q[++r] = v ;
            }else if ( dis[v] == dis[u] + 1 ){
                cnt[v] = cnt[v] + cnt[u] ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; i++ ){
        if ( cnt[i] == 2 ) ans++;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while ( t-- ){
        scanf("%d%lld",&n,&d);
        for ( int i = 1 ; i <= n ; i++ ) g[i].clear();
        for ( int i = 1 ; i <= n ; i++ ){
            scanf("%lld",&val[i]);
            if ( c <= 10 ){
                for ( int j = 1 ; j < i ; j++ ){
                    if ( val[i] - val[j] <= d ){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
        }
        ans = 0 ;
        if ( c <= 10 ){
            for ( int i = 1 ; i <= n ; i++ ){
                bfs(i);
            }
            printf("%lld\n",ans/2);
        }
    }
    return 0 ;
}
