#include <bits/stdc++.h>
typedef long long ll;

ll n, a[200005], e1[200005], e2[200005], sm, i, ps, j, ans;
char c[200005];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i){
        scanf("\n%lld %c", a + i, c + i); e1[i] = a[i] + e1[i - 1];
    }
    sm = e1[n];
    for(int i = n; 0 < i; --i) e2[i] = a[i] + e2[i + 1];
//    for(int i = 1; i <= n; ++i) printf("%lld %lld\n", e1[i], e2[i]);
    i = 1; j = n;
    while(i <= j){
//            printf("%lld %lld %lld %lld\n", i, j, ps, ans);
        if(e1[i] < e2[j]){
            if(e1[i] > (sm >> 1)) e1[i] = sm >> 1;
            if(c[i] != c[j]) ans += e1[i] - ps;
//            printf("+%lld - %lld\n", e1[i], ps);
            ps = e1[i]; ++i;
        }else if(e2[j] < e1[i]){
            if(e2[j] > (sm >> 1)) e2[j] = sm >> 1;
            if(c[i] != c[j]) ans += e2[j] - ps;
            ps = e2[j]; --j;
        }else{
            if(e1[i] > (sm >> 1)) e1[i] = sm >> 1;
            if(c[i] != c[j]) ans += e1[i] - ps;
            ps = e1[i]; ++i; --j;
        }
    }
    printf("%lld", ans);
    return 0;
}
