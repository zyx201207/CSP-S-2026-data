#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;
int n , m , a[N] , p[N];
bool vis[N];
int ans[N] , c[N];
struct edges {
    int v , next;
}e[N * 2];
int idx , head[N * 2];
void add(int u , int v) {
    e[++ idx] = {v , head[u]};
    head[u] = idx;
}
int dp[N];
int dfs(int u , int fa) {
    if(dp[u]) {
        return dp[u];
    }
    dp[u] = 0;
    //printf("%d %d\n" , u , fa);
    for(int j = head[u] ; j ; j = e[j].next) {
        int v = e[j].v;
        if(v != fa) {
            dp[u] += dfs(v , u);
        }
    }
    dp[u] ++;
    return dp[u];
}
int main() {
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    scanf("%d %d" , & n , & m);
    for(int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , & a[i]);
    }
    for(int i = n ; i >= 1 ; -- i) {
        if(p[a[i]] == 0) {
            p[a[i]] = i;
        }
    }
    for(int i = 1 ; i <= n ; ++ i) {
        for(int j = i ; j <= n ; j = p[a[j]] + 1) {
            if(vis[j]) {
                break;
            }
            vis[j] = 1;
            if(p[a[j]] <= n && p[a[j]] != j) {
                //printf("%d %d %d\n" ,i , j , p[a[j]]);
                add(j , p[a[j]]);
                add(p[a[j]] , j);
            }
            if(p[a[j]] == j && p[a[j]] + 1 <= n) {
               // printf("%d %d %d\n" ,i , j , j + 1);
                add(j , j + 1);
                add(j + 1 , j);
            }
        }
    }
    dfs(n , n);
    for(int i = 1 ; i <= n ; ++ i) {
        //printf("%d " , dp[i]);
        ans[a[i]] = max(ans[a[i]] , dp[i]);
    }
    //puts("");
    for(int i = 1 ; i <= m ; ++ i) {
        printf("%d " , ans[i]);
    }
    return 0;
}
