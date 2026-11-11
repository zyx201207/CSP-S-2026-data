#include <cstdio>

const int xn = 500005, xm = 300005;
int n, m, a[xn], lft[xn], lst[xm], dp[xm], cnt[xm];

int dfs(int x){
//    printf("dfs%d\n", x);
    if(dp[x]) dp[x];
    dp[x] = cnt[x];
    for(int i = lst[x]; i; i = lft[i]){
        if(i - 1 == lst[a[i - 1]]){
            dp[x] += dfs(a[i - 1]);
        }
    }
    return dp[x];
}

int main(){
    freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i); ++cnt[a[i]];
        lft[i] = lst[a[i]]; lst[a[i]] = i;
    }
    dp[0] = 1; dfs(a[n]);
    for(int i = 1; i <= m; ++i){
        printf("%d ", dp[i]);
    }
    return 0;
}
