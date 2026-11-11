#include<bits/stdc++.h>


const int MAXN = 2e5 + 10;

long long n, m, ans;
bool vis[MAXN];
long long a[MAXN];
long long dfs(long long now, long long val){
    if(now == m) return val;
    long long r = 0;
    for(int i = 1;i <= n;i++){
        if(vis[i]) continue;
        vis[i] = true;
        r = std::max(r, dfs(now + 1, (val & a[i])));
        vis[i] = false;
    }
    return r;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 1;i <= n;i++) scanf("%lld", a + i);
    if(m == 1){
        for(int i = 1;i <= n;i++) ans = std::max(ans, a[i]);
        printf("%lld", ans);
        return 0;
    }
    else if(m == n){
        ans = (1ll << 60) - 1;
        for(int i = 1;i <= n;i++) ans &= a[i];
        printf("%lld", ans);
        return 0;
    }
    printf("%lld", dfs(0, (1ll << 60) - 1));

    return 0;
}