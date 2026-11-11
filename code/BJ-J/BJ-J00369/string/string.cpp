#include <cstdio>
long long sum, ans, a[200005];
char c[200005];
long long max(long long a, long long b){
    return a > b ? a : b;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %c", &a[i], &c[i]);
        sum += a[i];
    }
    int lid = -1, rid = n;
    long long l = 0, r = 0;
    while(l + r < sum){
        if(l <= r){
            lid++;
            l += a[lid];
            ans += c[lid] != c[rid] ? a[lid] - max(0ll, l - r) : 0;
        }else{
            rid--;
            r += a[rid];
            ans += c[lid] != c[rid] ? a[rid] - max(0ll, r - l) : 0;
        }
    }
    printf("%lld", ans);
    return 0;
}
