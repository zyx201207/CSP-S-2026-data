#include <bits/stdc++.h>
#define int long long
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
using namespace std;
const int N = 2e5 + 2;
int n, a[N], l[N], r[N];
char c[N];
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n; int tot = 0;
    rep(i, 1, n) cin >> a[i] >> c[i], l[i] = tot + 1, tot += a[i], r[i] = tot;
    int p = 0, pl = 1, pr = n, res = 0;
    while (pl < pr) {
        int sl = r[pl] - p, sr = tot - p + 1 - l[pr];
        if (c[pl] == c[pr]) {
            if (sl > sr) p += sr, pr--;
            else if (sl < sr) p += sl, pl++;
            else p += sl, pl++, pr--;
        } else {
            if (sl > sr) res += sr, p += sr, pr--;
            else if (sl < sr) res += sl, p += sl, pl++;
            else res += sl, p += sl, pl++, pr--;
        }
    }
    cout << res << '\n';
    return 0;
}
/*
D:\GD-J04790\string\string.exe
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/