#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
long long m, a[500005];
main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for (int i = 1; i < n; i++){
        m -= i*(a[i+1]-a[i]);
        if (m >= 0) ans++;
        else break;
    }
    printf("%d", ans);
    return 0;
}