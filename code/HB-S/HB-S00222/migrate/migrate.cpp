#include <bits/stdc++.h>

using namespace std;
const long long N = 5000 + 5;
long long t , n , d , x[N] , di[N][N] , cnt[N][N];
struct ed {
    long long v , next;
}e[2 * N];
long long idx , head[2 * N];
void add(long long u , long long v) {
    e[++ idx] = {v , head[u]};
    head[u] = idx;
}
struct node {
    long long u , stp;
};
bool vis[N];
void bfs(long long u) {
    queue <node> q;
    q.push({u , 0});
    di[u][u] = 0;
    for(long long i = 1 ; i <= n ; ++ i) {
        vis[i] = 0;
    }
    while(! q.empty()) {
        node now = q.front();
        q.pop();
        long long nu = now.u , stp = now.stp;
        vis[nu] = 1;
        for(long long j = head[nu] ; j ; j = e[j].next) {
            long long v = e[j].v;
            if(di[u][v] == 0 && v != u) {
                cnt[u][v] ++;
                di[u][v] = stp + 1;
                q.push({v , stp + 1});
            } else if(di[u][v] == stp + 1) {
                cnt[u][v] ++;
            }
        }
    }
}
long long ans;
int main() {
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    scanf("%lld %lld" , & t , & t);
    while(t --) {
        memset(head , 0 , sizeof(head));
        ans = 0 , idx = 0;
        scanf("%lld %lld" , & n , & d);
        for(long long i = 1 ; i <= n ; ++ i) {
            scanf("%lld" , & x[i]);
        }
        for(long long i = 1 ; i <= n ; ++ i) {
            for(long long j = 1 ; j <= n ; ++ j) {
                di[i][j] = 0;
                cnt[i][j] = 0;
            }
        }
        for(long long i = 1 ; i <= n ; ++ i) {
            for(long long j = i + 1 ; j <= n ; ++ j) {
                if(x[j] - x[i] <= d) {
                    add(j , i);
                    add(i , j);
                } else {
                    break;
                }
            }
        }
        for(long long i = 1 ; i <= n ; ++ i) {
            bfs(i);
            for(long long j = 1 ; j <= n ; ++ j) {
                if(cnt[i][j] == 2) {
                    ans ++;
                }
            }
        }
        printf("%lld\n" , ans / 2);

    }
    return 0;
}
