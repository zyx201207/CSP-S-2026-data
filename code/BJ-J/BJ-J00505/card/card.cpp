#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 10;
int n, m, a[maxn];
inline int read(int &x) {
    x = 0; char c = getchar_unlocked();
    while (c > '9' || c < '0') c = c = getchar_unlocked();
    while (c <= '9' && c >= '0') { x = (x << 1) + (x << 3) + c - 48; c = c = getchar_unlocked(); }
    return x;
}
inline void write(int x) {
    if (x > 9) write(x / 10); putchar_unlocked(x % 10 + 48);
}
namespace spA {
    int cnt[maxn], b[maxn], ans[maxn], tot = 0, pre = 0;
    bool check() {
        for (int i = 1; i < n; i++) 
            if (a[i] > a[i + 1]) return false;
        return true;
    }
    inline void work() {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
            if (a[i] != a[i - 1]) b[++tot] = a[i];
        }
        for (int i = 1; i <= tot; i++) {
            pre += cnt[b[i]];
            ans[b[i]] = pre;
        }
        for (int i = 1; i <= m; i++) write(ans[i]), putchar_unlocked(' ');
        putchar_unlocked('\n');
    }
}
namespace force {
    int lst[maxn], tot, cnt[maxn], ans[maxn];
    struct node {
        int l, r;
        bool operator < (const node &o) const {
            return l < o.l;
        }
    } seg[maxn];
    inline void work() {
        memset(lst, 0, sizeof(lst));
        for (int i = 1; i <= n; i++) {
            if (lst[a[i]] == 0) {
                lst[a[i]] = i;
                continue;
            }
            seg[++tot] = {lst[a[i]], i - 1};
            lst[a[i]] = i;
        }
        sort(seg + 1, seg + tot + 1);
        for (int k = 1; k <= n; k++) {
            // start from k
            int it = k - 1;
            for (int j = 1; j <= m; j++) cnt[j] = 0;
            for (int i = k; i <= n; i++) cnt[a[i]]++;
            for (int i = 1; i <= tot; i++) {
                if (seg[i].l < it + 1) continue;
                for (int j = seg[i].l; j <= seg[i].r; j++) cnt[a[j]]--;
                it = seg[i].r;
            }
            for (int j = 1; j <= m; j++) 
                if (cnt[j] != 0) ans[j]++;
        }
        for (int i = 1; i <= m; i++) write(ans[i]), putchar_unlocked(' ');
        putchar_unlocked('\n');
    }
}
namespace spM {
    bool check() { return m <= 2; }
    int cnt1 = 0, cnt2 = 0, ans1 = 0, ans2 = 0;
    inline void work() {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) cnt1++;
            else cnt2++;
        }
        ans1 = ans2 = n;
        if (a[n] == 1) {
            ans2 -= cnt1;
        } else ans1 -= cnt2;
        write(ans1);
        putchar_unlocked(' ');
        write(ans2);
        putchar_unlocked('\n');
    }
}
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    if (spA::check()) spA::work();
    else if (spM::check()) spM::work();
    else force::work();
    return 0;
}