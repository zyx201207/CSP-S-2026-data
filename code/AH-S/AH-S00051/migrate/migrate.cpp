#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace usr
{
    const ll N = 2e6 + 5;
    ll a[N], f[5005], g[N]; // f:dis, g:cnt
    ll nxt[N];
    ll n, d, ans;
    void solve(ll cas)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n == 1)
        {
            cout << "0\n";
            return ;
        }
        if (cas <= 10) // n^2
        {
            ans = 0;
            for (int i = 1; i <= n; i++)
            {
                ll l = i, r = i + 1, ls = i, s = 1; // ls:min区间 s:最短路数量
                g[i] = 1;
                f[i] = 0;
                while (r <= n)
                {
                    while (a[r] - a[l] > d) s -= g[l++];
                    if (l == r) break ;
                    f[r] = f[l] + 1;
                    if (ls < l)
                    {
                        ls = l;
                        s = g[l];
                        while (ls + 1 <= n && f[ls + 1] == f[l]) s += g[++ls];
                    }
                    g[r] = s;
                    if (s == 2)
                    {
                        ans++;
                    }
                    r++;
                }
            }
            cout << ans << '\n';
        }
        else if (cas <= 12) // xz A
        {
            ll D = 0; // dis
            for (int i = 2; i <= n; i++)
            {
                if (a[i] - a[1] <= d) D++;
            }
            ll td = D + D - 1;
            ll mxd = n - 1;
            // mxd > td
            if (D <= 1) cout << "0\n";
            else cout << max(0ll, mxd - td + 1) << '\n';
            // cout << d << ' ' << a[2] - a[1] << ' ' << td << ' ' << mxd << '\n';
        }
        else // xz B/C
        {
            ans = 0;
            for (int l = 1, r = 1; l <= n; l++)
            {
                while (r < n && a[r + 1] - a[l] <= d) r++;
                nxt[l] = r;
                // cout << nxt[l] << ' ';
            }
            for (int i = 1; i <= n; i++)
            {
                ll pre1 = i, pre2 = 0, pre3 = 0;
                ll c1 = 1, c2 = 0;
                for (int dis = 1, now = nxt[i]; dis <= 30 && c1 <= 2; dis++, now = nxt[now])
                {
                    if (now == pre1) break ;
                    ll t1 = max(pre1, nxt[pre2]), t2 = max(pre1, nxt[pre3]);
                    if (c1 == 2)
                    {
                        if (t1 == now) break ;
                        ans += now - t1;
                    }
                    else
                    {
                        if (c2 == 1) ans += t1 - t2;
                        if (now <= t1)
                        {
                            if (c2 >= 2 || now <= t2) break ;
                            c1 += c2;
                            if (now - 1 > t2) c2 = c1;
                            else c2 = 2;
                        }
                        else
                        {
                            if (now - 1 > t1) c2 = c1;
                            else c2 = 2;
                        }
                    }
                    if (now > pre1 + 1) pre2 = now - 1;
                    else pre2 = 0, c2 = 0;
                    if (now > pre1 + 2) pre3 = now - 2;
                    else pre3 = 0;
                    pre1 = now;
                }
            }
            cout << ans << '\n';
        }
    }
    void main()
    {
        freopen("migrate.in", "r", stdin);
        freopen("migrate.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        // -Wall -Wextra -fsanitize=address,undefined
        ll T = 1, cas = 0;
        cin >> cas;
        cin >> T;
        while (T--) solve(cas);
    }
};
int main()
{
    usr::main();
    return 0;
}
/*
-1000000000000000000 -999997142608141581
*/