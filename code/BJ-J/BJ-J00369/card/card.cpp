#include <cstdio>
int n, m, a[500005], last[300005], son[500005], dp[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        son[i] = last[a[i]];
        last[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        dp[i] = dp[son[i]] + 1;
        if(last[a[i - 1]] == i - 1){
            dp[i] += dp[i - 1];
        }
    }
    for(int i = 1; i <= m; i++){
        printf("%d ", dp[last[i]]);
    }
    return 0;
}
