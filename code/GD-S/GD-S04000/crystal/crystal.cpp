bool st;
#include <bits/stdc++.h>
#define int long long
#define fo(i, a, b) for (int i(a); i <= (b); ++i)
#define dfo(i, a, b) for (int i(a); i >= (b); --i)
#define N 600005
#define M 600005
#define mod 998244353
#define B 805
using namespace std;
int n, m, a[N];
int su[B + 5], sum[B + 5][B + 5], bl, sy[N], l[B + 5], r[B + 5], fi[B + 5][B + 5], lst[B + 5][B + 5];
// int tr[N];
// inline int Q(int x)
// {
//     int ans = 0;
//     while (x)
//     {
//         ans += tr[x];
//         x -= (x & (-x));
//     }
//     return ans;
// }
// inline int query(int l, int r)
// {
//     return Q(r) - Q(l - 1);
// }
// inline void add(int x, int v)
// {
//     while (x < N)
//     {
//         tr[x] += v;
//         x += (x & (-x));
//     }
// }
// inline int query(int l, int r)
// {
//     int sum = 0, pos = l;
//     ++r;
//     dfo(i, 19, 0)
//     {
//         if (pos + (1 << i) <= r)
//         {
//             sum += st[pos][i];
//             pos += (1 << i);
//         }
//     }
//     return sum;
// }
inline int query(int L, int R)
{
    int ll = sy[L], rr = sy[R], ans = 0;
    if (L > R)
        return 0;
    if (ll == rr)
    {
        ++R;
        int kk = r[ll] - L + 1;
        ans += lst[ll][kk];
        // cout << lst[ll][kk] << ' ';
        kk = r[ll] - R + 1;
        ans -= lst[ll][kk];
        // cout << lst[ll][kk] << '\n';
        // cout << L << " " << R << " " << r[ll] - L + 1 << " " << r[ll] - R + 1 << '\n';
    }
    else
    {
        ans += sum[ll + 1][rr - 1];
        int kk = r[ll] - L + 1;
        ans += lst[ll][kk];
        kk = R - l[rr] + 1;
        ans += fi[rr][kk];
    }
    return ans;
}
inline void solve()
{
    cin >> n >> m;
    fo(i, 1, n)
    {
        cin >> a[i];
        sy[i] = (i - 1) / B + 1;
    }
    bl = sy[n];
    sort(a + 1, a + 1 + n);
    fo(i, 1, n)
    {
        if (!l[sy[i]])
        {
            l[sy[i]] = i;
        }
        r[sy[i]] = i;
    }
    fo(i, 1, bl)
    {
        fo(j, l[i], r[i])
        {
            su[i] += a[j];
        }
    }
    fo(i, 1, bl)
    {
        fo(j, i, bl)
        {
            sum[i][j] = sum[i][j - 1] + su[j];
        }
    }
    fo(i, 1, bl)
    {
        int cnt = 1;
        fo(j, l[i], r[i])
        {
            fi[i][cnt] = fi[i][cnt - 1] + a[j];
            ++cnt;
        }
    }
    fo(i, 1, bl)
    {
        int cnt = 1;
        dfo(j, r[i], l[i])
        {
            lst[i][cnt] = lst[i][cnt - 1] + a[j];
            ++cnt;
        }
    }
    // fo(i, 1, n)
    // {
    //     st[i][0] = a[i];
    // }
    // fo(j, 1, 19)
    // {
    //     fo(i, 1, n - (1 << j) + 1)
    //     {
    //         st[i][j] = st[i][j - 1] + st[i + (1 << j) - 1][j - 1];
    //     }
    // }
    // fo(i, 1, n)
    // {
    //     fo(j, i, n)
    //     {
    //         sum[i][j] = sum[i][j - 1] + a[j];
    //     }
    // }
    int ans = 0;
    // fo(i, 1, n)
    // {
    //     fo(j, 1, n)
    //     {
    //         int k = j, s1 = sum[i][k - 1], s2 = sum[k + 1][j], g1 = k - i, g2 = j - k;
    //         int num = g1 * a[k] - s1 + s2 - g2 * a[k];
    //         if (num <= m)
    //         {
    //             ans = max(ans, j - i + 1);
    //             // if (i == 1 && j == n)
    //             // {
    //             //     cerr << k << " " << a[k] << " " << g1 << " " << g2 << " " << s1 << " " << s2 << " " << num << '\n';
    //             //     cerr << g1 * a[k] - s1 << " " << s2 - g2 * a[k] << '\n';
    //             // }
    //         }
    //     }
    // }
    // fo(i, 1, n) add(i, a[i]);
    fo(i, 1, n)
    {
        int l = i + ans - 1, r = n, mid, an = l;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            int num = (mid - i) * a[mid] - query(i, mid - 1);
            // cout << i << " " << mid << " " << ans << " " << num << " " << query(i, mid - 1) << '\n';
            if (num <= m)
                an = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        // cout << i << " " << an << '\n';
        ans = max(ans, an - i + 1);
    }
    cout << ans << '\n';
}
bool en;
signed main()
{
    // int ti = clock();
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    // cerr << clock() - ti << "ms\n";
    // cerr << abs(&st - &en) * 1.0 / 1024.0 / 1024.0 << "MB";
}
/*
16:35 know how to do n log n but coding n^2 first
16:40 n^2 WA crystal 3
16:46 n^2 ok 45pts now 45+60+32=147
16:47 coding n log n
16:51 ending n log n but not ok
16:52 find that n log n is not true,coding n log^2 n
16:59 ending n log^2 n ok, but in the biggest case use 1.2sec
17:00 start ka'chang
17:01 in CCF's biggest case run 0.854sec continue
17:03 0.842sec
17:05 I find that can do in n log n with block
17:24 n log n is ok but crystal4 is WA
17:26 find that n log^2 n wa also
17:31 let n log^2 n correct
17:32 let n log n correct  tim:0.682sec
17:35 check memery and tim,  tim:0.677s,mem:22.21MB  now:100+60+32+0=192pts
18:03 NOI LINUX correct tim:0.1s,mem:22MB
跳 T4
18:21 last check ok
*/
/*
5 5
1 2 4 8 9
*/