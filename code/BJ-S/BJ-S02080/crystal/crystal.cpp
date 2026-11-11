#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int nn = 5e5 + 5;
ll a[nn], sum[nn];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, ans = 0;
    ll m;
    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; ++i){
        int l = 1, r = i - 1, res = 0;
        while(l <= r){
            int mid = l + r >> 1;
            if(a[i] * (i - mid) - sum[i - 1] + sum[mid - 1] <= m){
                r = mid - 1;
                res = i - mid;
            }else l = mid + 1;
        }
        ans = max(ans, res + 1);
    }
    printf("%d", ans);
    return 0;
}