#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, T, n, d, a[2000005], ed[2000005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--)
    {
        if (c == 1 || c == 2)
        {
            cin >> n >> d;
            for (int i = 1; i <= n; i++) cin >> a[i];
            int res = 0;
            for (int l = 1; l <= n; l++)
            {
                for (int r = l + 2; r <= n; r++)
                {
                    int cnt = 0, len = r - l - 1, dmin = LLONG_MAX;
                    vector<int> v;
                    for (int b = 0; b < (1 << len); b++)
                    {
                        int bit = b;
                        v.push_back(l);
                        int now = 0;
                        while (bit)
                        {
                            ++now;
                            if (bit & 1) v.push_back(now + l);
                            bit >>= 1;
                        }
                        v.push_back(r);
                        bool flag = 0;
                        for (int i = 1; i < v.size(); i++)
                        {
                            // cout << v[i] << ' ';
                            if (a[v[i]] - a[v[i - 1]] > d)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        // cout << '\n';
                        if (!flag)
                        {
                            // cout << "upd: " << l << ' ' << r << ' ' << dmin << ' ' << v.size() << ' ' << cnt << '\n';
                            if (dmin == v.size()) cnt++;
                            else if (dmin > v.size()) dmin = v.size(), cnt = 1;
                        }
                        // else cout << "\n\n";
                        v.clear();
                    }
                    if (cnt == 2) res++;
                    // cout << "rd finish\n" << flush;
                }
            }
            cout << res << '\n';
        }
        else if (c <= 10)
        {
            cin >> n >> d;
            for (int i = 1; i <= n; i++) cin >> a[i], ed[i] = 1;
            int l = 1, r = 1, res = 0;
            while (l <= n)
            {
                if (a[r] - a[l] <= d && r <= n) r++;
                else ed[l] = r - 1, l++;
            }
            // for (int i = 1; i <= n; i++) cout << ed[i] << ' ';
            // cout << '\n';
            // cout << "tag1\n" << flush;
            for (int l = 1; l <= n; l++)
            {
                for (int r = l + 2; r <= n; r++)
                {
                    if (a[r] - a[l] <= d) continue;
                    // cout << l << ' ' << r << '\n' << flush;
                    int now = l, cnt = 0, flag = 1;
                    vector<int> v;
                    v.push_back(l);
                    while (now < r)
                    {
                        if (now == ed[now])
                        {
                            flag = 0;
                            break;
                        }
                        v.push_back(now = ed[now]);
                    }
                    if (!flag) continue;
                    now = r;
                    int pos = v.size() - 2;
                    // cout << "tag\n" << flush;
                    while (now > l)
                    {
                        now = lower_bound(ed + 1, ed + n + 1, now) - ed;
                        // cout << now << ' ' << v[pos] << '\n' << flush;
                        if (now > l) cnt += abs(now - v[pos--]);
                        if (cnt > 1) break;
                    }
                    // cout << cnt << ' ' << r << ' ' << v.back() << '\n' << flush;
                    if (cnt == 1) res++;
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}


/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/


/*
思路&瞎写区
16:01 剩余 2.5h
1. n \le 9
n^3*2^n 枚举两个点，子集枚举暴力check双径对个数
2. spe A
组合数?
16:59 坏了怎么才调出暴力
100+100+8+0=208，感觉今年1=线会很高啊
别挂别挂别挂
t2这让我做出来了，那1=线200？
18:25 100+100+[8,24]+0=[208.224]
*/