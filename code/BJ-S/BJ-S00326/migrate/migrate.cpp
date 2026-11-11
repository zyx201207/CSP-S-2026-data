#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, ans, m;
long long x[2000006], d;
int f(int s, int e, int dis){
    int r = 2000006, u;
    if (s == e) return dis;
    for (int i = e-1; i >= s; i--){
        if (x[e]-x[i] <= d){
            u = f(s, i, dis+1);
            if (u == r && dis == 0) m++;
            else if (u < r && dis == 0) m = 1;
            r = min(r, u);
        }
        else break;
    }
    return r;
}
main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--){
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
        ans = 0;
        for (int i = 1; i < n; i++){
            for (int j = i+1; j <= n; j++){
                m = 0;
                f(i, j, 0);
                if (m == 2) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
