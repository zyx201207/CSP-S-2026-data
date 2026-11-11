#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], sum[500005], ans;
int main(){
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]), sum[i] = sum[i-1] + a[i];
        long long l = 1, r = i, mid, num = i;
        while(l <= r){
            mid = (l + r) / 2;
            if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) > m) l = mid +1;
            else r = mid - 1, num = mid;
        } ans = max(ans, i - num + 1);
    } printf("%lld\n", ans);
    return 0;
}
