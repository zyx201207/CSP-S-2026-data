#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], s[N], ans;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int l = 1, i = 1; i <= n;) {
        int j = i;
        for (; j < n and a[i] == a[j + 1]; j++);
        while (l < i and (__int128)(a[i] * (i - l) - (s[i - 1] - s[l - 1])) > m)
            l++;
        ans = max(ans, j - l + 1);
        i = j + 1;
    }
    cout << ans;
    return 0;
}