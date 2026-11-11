#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll m;
int a[500011], ans;
ll pre[500011];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        int l = 0, r = i, mid = 0;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(1ll * (i - mid + 1) * a[i] - pre[i] + pre[mid - 1] <= m) {
                r = mid;
            }else {
                l = mid;
            }
        }
        ans = max(ans, i - r + 1);
    }
    printf("%d\n", ans);
    return 0;
}