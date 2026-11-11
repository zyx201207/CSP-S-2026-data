#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans;
ll a[500100], sufs[500100], suf[500100], m;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    sufs[n] = suf[n] = 0ll;
    for (int i = n - 1; i >= 1; i--)
        sufs[i] = sufs[i + 1] + a[i + 1] - a[i],
        suf[i] = suf[i + 1] + sufs[i];
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (suf[mid] - suf[i] - sufs[i] * (i - mid) <= m)
                r = mid;
            else
                l = mid;
        }
        ans = max(ans, i - l);
    }
    printf("%d\n", ans);
}