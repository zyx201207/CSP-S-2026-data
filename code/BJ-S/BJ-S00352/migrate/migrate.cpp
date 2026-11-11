#include <cstdio>
long long x[2000005];
int main(){
    freopen("migrate1.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n;
    long long d;
    scanf("%d %d", &c, &t);
    while(t--){
        scanf("%d %lld", &n, &d);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", &x[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
