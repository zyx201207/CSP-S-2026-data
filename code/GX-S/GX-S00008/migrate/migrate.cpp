#include <bits/stdc++.h>
#define sint static int
#define cint const int
#define ll long long
#define sll static ll
#define cll const ll
#define pii pair<int, int>
#define isd(x) ((x) >= '0' && (x) <= '9')
#define rep(_, start, stop) for (int _ = (start); _ <= (stop); ++_)
using namespace std; constexpr int N = 2e6;
sint c, T, n, valid[N + 5]; sll d, x[N + 5];
sint dis[N + 5], pref[N + 5], ato[N + 5]; sll dp[N + 5], ans; static stack<int> st;
sint circle[N + 5], rtc[N + 5], most[N + 5];
sll read()
{
    bool neg = false; ll res = 0; int c = getchar(); while (!isd(c)) { if (c == '-') { neg = true; } c = getchar(); }
    while (isd(c)) { res = (res << 1) + (res << 3) + c - '0'; c = getchar(); } return neg ? -res : res;
}
void write(cll x) { if (x >= 10) { write(x / 10); } putchar(x % 10 + '0'); }
int main()
{
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    c = read(); T = read() + 1;
    while (--T)
    {
        n = read(); d = read();
        rep(i, 1, n)
        {
            x[i] = read(); int L = 1, R = i; valid[i] = i;
            while (L <= R)
            {
                cint mid = (L + R) >> 1;
                if (x[i] - x[mid] <= d) { valid[i] = min(valid[i], mid); R = mid - 1; } else { L = mid + 1; }
            }
        }
        ans = 0;
        if (c <= 10)
        {
            rep(s, 1, n)
            {
                pref[s - 1] = 0; dis[s] = 0; dp[s] = 1; pref[s] = 1; st.push(s);
                rep(t, s + 1, n)
                {
                    cint pos = max(s, valid[t]);
                    dis[t] = dis[pos] + 1;
                    if (dis[t] != dis[t - 1]) { while (!st.empty()) { ato[st.top()] = t - 1; st.pop(); } }
                    st.push(t); dp[t] = pref[ato[pos]] - pref[pos - 1];
                    if (dp[t] == 2) { ++ans; } pref[t] = pref[t - 1] + dp[t];
                }
            } write(ans); putchar('\n');
            continue;
        }
        rep(lt, 1, n)
        {
            int pre = valid[lt], L = lt, R = n, res = lt;
            while (L <= R)
            {
                cint mid = (L + R) >> 1;
                if (x[mid] - x[pre] <= d) { res = max(res, mid); L = mid + 1; }
                else { R = mid - 1; }
            }
            circle[lt] = pre; rtc[pre] = res;
        }
        sort(circle + 1, circle + n + 1); int newsz = unique(circle + 1, circle + n + 1) - circle - 1;
        for (int i = n; i >= 1; --i)
        {
            if (!rtc[i]) { continue; } if (rtc[i] == i) { most[i] = i; continue; }
            if (!rtc[rtc[i]]) { most[i] = rtc[i]; } else { most[i] = most[rtc[i]]; }
        }
        rep(s, 1, n)
        {
            cint pos = upper_bound(circle + 1, circle + newsz + 1, s) - circle - 1;
            cint rt = rtc[circle[pos]]; if (rt == circle[pos] || !rtc[rt - 1]) { continue; }
            ans += most[rt - 1] - rt;
        } write(ans); putchar('\n');
    }

    return 0;
}
