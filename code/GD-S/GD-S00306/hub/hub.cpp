#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define urep(i, r, l) for(int i = (r); i >= (l); i--)
constexpr int _ = 2000005, mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

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
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    return 0;
}