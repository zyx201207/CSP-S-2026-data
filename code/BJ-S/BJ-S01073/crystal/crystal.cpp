#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans = -1;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1, r = 1, d = 0;
    while(l <= r && r <= n) {
        while(d > m) d -= a[r] - a[l++];
        ans = max(ans, r - l + 1);
        r++; d += (a[r] - a[r - 1]) * (r - l);
    }
    printf("%lld", ans);
}
