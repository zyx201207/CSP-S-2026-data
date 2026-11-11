#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, l=1, r=0, li, ri, ans = 0;
int a[200005];
char c[200005];
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;++i) {
        cin >> a[i] >> c[i];
        r += a[i];
    }
    li = 1, ri = n;
    while (l < r && li < ri) {
        if (a[li] > a[ri]) {
            if (c[li] != c[ri]) {
                ans += a[ri];
            }
            r -= a[ri], l += a[ri], a[li] -= a[ri];
            ri--;
        }
        else {
            if (c[li] != c[ri]) {
                ans += a[li];
            }
            l += a[li], r -= a[li], a[ri] -= a[li];
            li++;
        }
    }
    cout << ans;
    return 0;
}
