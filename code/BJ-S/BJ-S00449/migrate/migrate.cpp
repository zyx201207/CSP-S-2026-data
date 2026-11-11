#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nr = 2e6 + 10;
const int inf = 9e18;
int n, d, a[nr];

namespace n2
{
    void solve()
    {
        int res = 0;
        for (int x = 1; x <= n; x++)
        {
            vector<int> pt; pt.push_back(x);
            for (int y = x + 1, cnt = 0; y <= n; y++)
            {
                if (a[y] - a[y - 1] > d || cnt > 1) break;
                bool add = false, out = false;
                if (pt.size() > 1 && pt.back() - 1 != pt[pt.size() - 2])
                {
                    if (a[y] - a[pt.back() - 2] <= d) out = true;
                    else if (a[y] - a[pt.back() - 1] <= d)
                    {
                        cnt++, add = true;
                        if (pt.size() > 2 && pt.back() - 1 != pt[pt.size() - 2]
                            && a[pt.back() - 1] - a[pt[pt.size() - 2] - 1] <= d) cnt--, add = false, out = true;
                    }
                }
                if (a[y + 1] - a[pt.back()] > d)
                {
                    if (out) break;
                    pt.push_back(y), add = false;
                }
                if (cnt == 1 && !out) res++;//, cout << x << " " << y << '\n';
                if (add) cnt--;
            }
        }
        cout << res << '\n';
    }
}

namespace A
{
    void solve()
    {
        int res = 0;
        vector<int> pt; pt.push_back(1);
        for (int y = 2, cnt = 0; y <= n; y++)
        {
            if (a[y] - a[y - 1] > d || cnt > 1) break;
            bool add = false, out = false;
            if (pt.size() > 1 && pt.back() - 1 != pt[pt.size() - 2])
            {
                if (a[y] - a[pt.back() - 2] <= d) out = true;
                else if (a[y] - a[pt.back() - 1] <= d)
                {
                    cnt++, add = true;
                    if (pt.size() > 2 && pt.back() - 1 != pt[pt.size() - 2]
                        && a[pt.back() - 1] - a[pt[pt.size() - 2] - 1] <= d) cnt--, add = false, out = true;
                }
            }
            if (a[y + 1] - a[pt.back()] > d)
            {
                if (out) break;
                pt.push_back(y), add = false;
            }
            if (cnt == 1 && !out) res += n - y + 1;
            if (add) cnt--;
        }
        cout << res << '\n';
    }
}

namespace B
{
    void solve()
    {
        ;
    }
}

void clear();
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int CASE, T; cin >> CASE >> T;
    while (T--)
    {
        cin >> n >> d;
        clear();
        for (int i = 1; i <= n; i++) cin >> a[i]; a[n + 1] = inf;
        if (CASE <= 10) n2::solve();
        else if (CASE <= 12) A::solve();
        else if (CASE <= 14) B::solve();
    }
    return 0;
}

void clear()
{
    ;
}
