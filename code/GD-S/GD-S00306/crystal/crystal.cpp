#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define urep(i, r, l) for(int i = (r); i >= (l); i--)
constexpr int _ = 500005, mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[_], s[_];
int ans = 0;

inline int rd()
{
    signed c = getchar();
    int res = 0, f = 1;
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) res = res * 10 + (c ^ 48);
    return res * f;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = rd(), m = rd();
    rep(i, 1, n) a[i] = rd();
    sort(a + 1, a + n + 1);
    rep(i, 1, n) s[i] = s[i-1] + a[i];
    rep(i, 1, n)
    {
        // (i - j + 1) * a[i] - (s[i] - s[j-1]) <= m
        int l = 1, r = i, mid;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if((i - mid + 1) * a[i] - (s[i] - s[mid-1]) <= m) ans = max(ans, i - mid + 1), r = mid - 1;
            else l = mid + 1; 
        }
    }
    cout << ans;
    return 0;
} // n log n