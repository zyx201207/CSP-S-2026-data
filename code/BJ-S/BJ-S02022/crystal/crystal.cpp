#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)) f = (c == '-' ? -1 : f), c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int N = 5e5 + 5;
int n, a[N], m, ans;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i, as = i, x = a[i] - a[i - 1];
        while(l <= r) {
            int mid = l + r >> 1;
            if(x * (i - mid + 1) - (a[i] - a[mid - 1]) <= m) as = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - as + 1);
    }
    cout << ans;
    return 0;
}
