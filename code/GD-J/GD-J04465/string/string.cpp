#include <bits/stdc++.h>
#define int long long
#define fo(i, a, b) for (int i(a); i <= (b); ++i)
#define dfo(i, a, b) for (int i(a); i >= (b); --i)
#define mod 998244353
#define M 500005
#define N 500005
using namespace std;
inline int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int n, sum, ans;
struct node
{
    int num;
    char c;
} a[N];
inline void solve()
{
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i].num >> a[i].c;
        sum += a[i].num;
    }
    int cnt = 0, l = 1, r = n, cnt2 = 0, lus = 0;
    sum /= 2;
    while (cnt < sum && l < r)
    {
        int wi = cnt + a[l].num;
        if (cnt2 + a[r].num - lus <= wi && l < r)
        {
            if (a[r].c != a[l].c)
                ans += a[r].num - lus;
            cnt2 += a[r].num - lus;
            --r;
            lus = 0;
        }
        while (cnt2 + a[r].num <= wi && l < r)
        {
            if (a[r].c != a[l].c)
                ans += a[r].num;
            cnt2 += a[r].num;
            --r;
        }
        int cha = wi - cnt2;
        // cout << l << " " << r << " " << cha << '\n';
        if (lus != 0)
        {
            lus += cha;
            if (a[l].c != a[r].c)
            {
                ans += cha;
            }
            cnt2 += cha;
        }
        else
        {
            lus = cha;
            if (a[l].c != a[r].c)
            {
                ans += cha;
            }
            cnt2 += cha;
        }
        cnt += a[l].num;
        ++l;
    }
    cout << ans;
}
signed main()
{
    freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}
/*
5
4 h
4 w
1 m
4 o
5 e

*/