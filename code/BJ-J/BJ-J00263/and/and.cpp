#include <bits/stdc++.h>

int n, m, tp[200005], a[200005], mtp, b[200005], ans;
bool bn[200005][32];

inline void tb(int x, int i){
//    printf("tb%d %d\n", x, i);
    int p = 0;
    while(x){
        bn[i][p] = (bool)(x & 1); x >>= 1; ++p;
//        printf("%d", bn[i][p] ? 1 : 0);
    }
    tp[i] = p - 1; mtp = std::max(mtp, tp[i]);
//    putchar(012);
}

int main(){
    freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; ++i){
        int tmp; scanf("%d", &tmp);
        tb(tmp, i); a[i] = i;
    }
    for(int i = mtp; 0 <= i; --i){
//        putchar(012);
        int tmp = 0;
        for(int j = 1; j <= n; ++j){
            if(bn[a[j]][i]) b[++tmp] = a[j];
        }
        if(tmp < m) continue;
        n = tmp; ans += (1 << i);
        for(int j = 1; j <= n; ++j) a[j] = b[j];
//        printf("when %d\n", i);
//        for(int j = 1; j <= n; ++j) printf("%d ", a[j]);
    }
    printf("%d", ans);
    return 0;
}
