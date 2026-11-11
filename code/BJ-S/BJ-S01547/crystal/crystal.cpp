#include <bits/stdc++.h>
using namespace std;

long long ans = 0, n, m, a[500005], suf[500005];

long long calc(long long l, long long r){
    long long d1 = a[r] * (r - l + 1);
    long long d2 = suf[r] - suf[l - 1];
    return d1 - d2;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (long long i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; i++){
        suf[i] = suf[i - 1] + a[i];
    }
    long long l = 1, r = 0;
    while (r <= n){
        long long now = 2e18;
        if (r < l){
            r ++;
            if (r > n){
                break ;
            }
            now = calc(l, r);
            if (now <= m){
                ans = max(ans, r - l + 1);
            }
            continue ;
        }
        r++;
        if (r > n) break ;
        while (calc(l, r) > m && l <= r){
            l++;
        }
        now = calc(l, r);
        if (l <= r && now <= m){
            ans = max(ans, r - l + 1);
        }
    }
    printf("%lld", ans);
    return 0;
}
