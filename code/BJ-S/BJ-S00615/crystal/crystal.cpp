#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;

const int maxn = 5e5 + 10, inf = 1e18, mod = 1e9 + 7;
int a[maxn], sum[maxn];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
    int ans = 0;
    for (int i = 1; i <= n; ) {
        int cnt = 0, j = i;
        while (a[j] == a[i]) j++, cnt++;
        int l = 1, r = i - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid) - sum[i - 1] + sum[mid - 1] <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + cnt), i = j;
    }
    cout << ans;
    return 0;
}
/*
g++ crystal.cpp -o a -O2 -std=c++14 -fsanitize=address,leak,undefined
洛谷uid 510822 叫Milthm（极品id好吧，你等Milthm做大做强的
崩铁uid忘了，绝区零也忘了
Phigros rks16.03 Milthm reality12.68 Chunithm reality15.23
别的忘了
*/