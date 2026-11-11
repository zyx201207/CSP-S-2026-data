#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5;
int n;
ll m, a[MAXN + 5];
ll sum[MAXN + 5];
ll calc(int l, int r) {
    return -sum[r] + sum[l - 1] + (r - l + 1) * a[r];
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int r = 1, l = 1; r <= n; ++r) {
        while (calc(l, r) > m) l++;
        ans = max(ans, r - l + 1);
    }
    cout<<ans;
    return 0;
}