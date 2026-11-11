#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
char c[N + 5];
int a[N + 5], pre[N + 5], post[N + 5];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> c[i];
    for (int i = 1; i <= n; i ++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = n; i >= 1; i --)
        post[i] = post[i + 1] + a[i];
    int mid = pre[n] + 1;
    mid >>= 1;
    int lr = 1;
    while (lr <= n && !(pre[lr - 1] + 1 <= mid && mid <= pre[lr]))
        lr ++;
    int rl = n;
    while (rl >= 1 && !(post[rl + 1] + 1 <= mid && mid <= post[rl]))
        rl --;
    if (lr == rl) {
        int p = mid - pre[lr - 1];
        for (int i = n; i >= lr; i --)
            a[i + 1] = a[i], c[i + 1] = c[i];
        a[lr] = p;
        a[lr + 1] -= p;
        if (pre[n] & 1) a[lr + 1] ++;
        rl = lr + 1;
        n ++;
        memset(pre, 0, sizeof pre);
        memset(post, 0, sizeof post);
        for (int i = 1; i <= n; i ++)
            pre[i] = pre[i - 1] + a[i];
        for (int i = n; i >= 1; i --)
            post[i] = post[i + 1] + a[i];
    }
    // Modifile Segment 1
    cerr << lr << " " << rl << endl;
    int r = n, ruse = 0, ans = 0;
    for (int l = 1; l <= lr; l ++) {
        while (r >= rl && pre[l] >= post[r]) {
            // Checkout this segment
            if (c[l] != c[r]) {
                ans += a[r] - ruse;
                cerr << l << " " << r << " " << a[r] - ruse << endl;
                ruse = 0;
            }
            r --;
        }
        int d = pre[l] - post[r + 1];
        // Segment R will use `d` char(s)
        if (pre[l] < post[r]) {
            int add = d - ruse;
            ruse = d;
            if (c[l] != c[r]) {
                ans += add;
                cerr << l << " " << r << " " << add << endl;
            }
        }
    }
    cout << ans;
    return 0;
}