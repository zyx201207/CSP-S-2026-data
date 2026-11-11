#include <bits/stdc++.h>
#define ll long long
#define max(a, b) ((a) > (b) ? a : b)
using namespace std;
ll read()
{
    ll i = 0, s = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') s = -1, c = getchar();
    while(c >= '0' && c <= '9') i = i * 10 + c - '0', c = getchar();
    return i * s;
}
const int N = 5e5 + 5;
int n;
ll m, a[N], s[N], ans;
inline ll qsum(int l, int r) {return s[r] - s[l - 1];}
inline bool chk(ll l, ll r)
{
    return (r - l + 1) * a[r] - qsum(l, r) <= m;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int x = 1; x <= n; ++x) a[x] = read();
    sort(a + 1, a + n + 1);
    for(int x = 1; x <= n; ++x)
    {
        s[x] = s[x - 1] + a[x];
        int l = 1, r = x;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(chk(mid, x)) r = mid - 1;
            else l = mid + 1;
        } // ans: l
        ans = max(ans, x - l + 1);
    }
    printf("%lld\n", ans);
    return 0;
}