#include <bits/stdc++.h>

using namespace std;
const int N = 505 , M = 5e5 + 5;
int n , m , d , q , x , y , w[M] ,c[N][M];
long long di[N][N];
int p[M][20] , id[M];
int main() {
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    scanf("%d %d %d %d %d" , & n , & n , & m , & d , & q);
    for(int i = 1 ; i <= m ; ++ i) {
        scanf("%lld" , & w[i]);
    }
    for(int i = 1 ; i <= n ; ++ i) {
        int k;
        scanf("%d" , & k);
        for(int j = 1 ; j <= k ; ++ j) {
            int t1 , t2;
            scanf("%d %d" , & t1 , & t2);
            c[i][t1] = t2;
            p[t1][++ id[t1]] = i;
        }
    }
    for(int i = 1 ; i <= n ; ++ i) {
        for(int j = 1 ; j <= n ; ++ j) {
            di[i][j] = 1e18;
        }
    }
    for(int i = 1 ; i <= m ; ++ i) {
        for(int j = 1 ; j < id[i] ; ++ j) {
            for(int k = j + 1 ; k <= id[i] ; ++ k) {
                di[p[i][j]][p[i][k]] = min((long long)c[p[i][j]][i] + (long long)c[p[i][k]][i] , di[p[i][j]][p[i][k]]);
                di[p[i][k]][p[i][j]] = di[p[i][j]][p[i][k]];
            }
        }
    }
    for(int i = 1 ; i <= n ; ++ i) {
        for(int j = 1 ; j <= n ; ++ j) {
            if(i == j) {
                continue;
            }
            for(int k = 1 ; k <= n ; ++ k) {
                if(k == i || k == j) {
                    continue;
                }
                di[j][k] = min(di[j][k] , di[j][i] + di[i][k]);
            }
        }
    }
    for(int i = 1 ; i <= q ; ++ i) {
        scanf("%d %d" , & x , & y);
        long long ans = 1e18;
        for(int j = 1 ; j <= id[x] ; ++ j) {
            for(int k = 1 ; k <= id[y] ; ++ k) {
                int pj = p[x][j] , pk = p[y][k];
                if(pj == pk) {
                    ans = min(ans , (long long)w[x] + (long long)w[y] + (long long)c[pj][x] + (long long)c[pk][y]);
                }
                ans = min(ans ,  (long long)c[pj][x] + (long long)c[pk][y] + di[pj][pk] + (long long)w[x] + (long long)w[y]);
            }
        }
        printf("%lld\n" , ans);
    }
    return 0;
}
