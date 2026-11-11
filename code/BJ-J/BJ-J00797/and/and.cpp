#include<bits/stdc++.h>
using namespace std;
int n, m, a[2005], f[2005][2005], ans, maxn, mx[2005], as;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        mx[i] = max(mx[i], a[i]);
    }
    if(m == 1){
        for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
        printf("%d", ans);
    }
    else if(m == 2){
        for(int i = 1; i < n; i++)
            for(int j = i + 1; j <= n; j++) maxn = max(maxn, a[i] & a[j]);
        printf("%d", maxn);
    }
    else{
        memset(f, -0x3f, sizeof f);
        for(int i = 1; i <= n; i++) f[i][0] = 0;
        for(int i = 1; i <= n; i++) f[i][1] = mx[i];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] & a[i]);
        for(int i = m; i <= n; i++) as = max(as, f[i][m]);
        printf("%d", as);
    }
}
