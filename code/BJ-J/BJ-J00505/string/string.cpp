#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 4e5 + 10;
int n, tot, ed[maxn], cnt, pre[maxn], suf[maxn], ans;
struct node {
    int x;
    char c;
} a[maxn], b[maxn];
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].c;
        if (tot == 0 || a[i].c != b[tot].c) {
            tot++;
            b[tot] = a[i];
        } else b[tot].x += a[i].x;
    }
    for (int i = 1; i <= tot; i++) pre[i] = pre[i - 1] + b[i].x;
    for (int i = tot; i >= 1; i--) suf[i] = suf[i + 1] + b[i].x;
    reverse(suf + 1, suf + tot + 1);
    if (pre[tot] & 1) {
        int mid = (pre[tot] + 1) >> 1;
        for (int i = 1; i <= tot; i++) {
            if (pre[i] >= mid) break;
            ed[++cnt] = pre[i];
        }
        for (int i = 1; i <= tot; i++) {
            if (suf[i] >= mid) break;
            ed[++cnt] = suf[i];
        }
    } else {
        int mid = pre[tot] >> 1;
        for (int i = 1; i <= tot; i++) {
            if (pre[i] > mid) break;
            ed[++cnt] = pre[i];
        }
        for (int i = 1; i <= tot; i++) {
            if (suf[i] > mid) break;
            ed[++cnt] = suf[i];
        }
    }
    sort(ed + 1, ed + cnt + 1);
    cnt = unique(ed + 1, ed + cnt + 1) - ed - 1;
    // for (int i = 1; i <= cnt; i++) cout << ed[i] << " \n"[i == n];
    for (int i = 1; i <= cnt; i++) {
        int l = lower_bound(pre + 1, pre + tot + 1, ed[i]) - pre;
        int r = lower_bound(suf + 1, suf + tot + 1, ed[i]) - suf;
        r = tot - r + 1;
        if (b[l].c != b[r].c) ans += ed[i] - ed[i - 1];
        // cout << ed[i] << ": " << b[l].c << " " << b[r].c << "\n";
    }
    cout << ans << "\n";
    return 0;
}