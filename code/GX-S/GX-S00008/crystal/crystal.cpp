#include <bits/stdc++.h>
#define sint static int
#define cint const int
#define ll long long
#define sll static ll
#define isd(x) ((x) >= '0' && (x) <= '9')
#define rep(_, start, stop) for (int _ = (start); _ <= (stop); ++_)
using namespace std; constexpr int N = 5e5;
sint n, ans; sll m, a[N + 5], pref[N + 5];
sll read()
{
    bool neg = false; ll res = 0; int c = getchar(); while (!isd(c)) { if (c == '-') { neg = true; } c = getchar(); }
    while (isd(c)) { res = (res << 1) + (res << 3) + c - '0'; c = getchar(); } return neg ? -res : res;
}
int main()
{
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    n = read(); m = read(); rep(i, 1, n) { a[i] = read(); } sort(a + 1, a + n + 1);
    rep(i, 1, n)
    {
        pref[i] = pref[i - 1] + a[i];
        int L = 1, R = i, res = n + 1;
        while (L <= R)
        {
            cint mid = (L + R) >> 1;
            if (a[i] * (i - mid + 1) - (pref[i] - pref[mid - 1]) <= m) { res = min(res, mid); R = mid - 1; }
            else { L = mid + 1; }
        } ans = max(ans, i - res + 1);
    } cout << ans << '\n'; return 0;
}
