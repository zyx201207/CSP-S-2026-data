
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 2000006

using ll = long long;

int Tid;

int n;
ll d;
ll a[MAXN];

int tl[MAXN], tr[MAXN];
int tll[MAXN], tlr[MAXN];
int trl[MAXN], trr[MAXN];

ll dl[MAXN], dr[MAXN];

void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = -4e18, a[n + 1] = 4e18;
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j < n && a[j + 1] - a[i] <= d)
        {
            j++;
        }
        tr[i] = j;
    }
    for (int i = n, j = n; i; i--)
    {
        while (j > 1 && a[i] - a[j - 1] <= d)
        {
            j--;
        }
        tl[i] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        dl[i] = 1;
        int l = lower_bound(tr + 1, tr + n + 1, i) - tr,
            r = upper_bound(tr + 1, tr + n + 1, i) - tr - 1;
        r = min(r, i - 1);
        trl[i] = l, trr[i] = r;
        if (tl[i] != i && tr[tl[i]] == i)
        {
            dl[i] += dl[tl[i]];
            l = max(l, tl[i] + 1);
        }
        dl[i] += r - l + 1;
        // clog << dl[i] << ' ';
    }
    // clog << endl;
    for (int i = n; i; i--)
    {
        dr[i] = 1;
        int l = lower_bound(tl + 1, tl + n + 1, i) - tl,
            r = upper_bound(tl + 1, tl + n + 1, i) - tl - 1;
        l = max(l, i + 1);
        tll[i] = l, tlr[i] = r;
        if (tr[i] != i && tl[tr[i]] == i)
        {
            dr[i] += dr[tr[i]];
            r = min(r, tr[i] - 1);
        }
        dr[i] += r - l + 1;
    }
    ll res = 0;
    for (int i = 1; i < n; i++)
    {
        if (tr[i] < i + 1) // make sure that i can reach i+1
        {
            continue;
        }
        ll cl = 0, cr = 0;
        { // calc cl
            int l = max(trl[i + 1], tl[i]), r = min(trr[i + 1], i - 1);
            // clog << ' ' << l << ' ' << r << ' ' << tl[i] << ' ' << tr[tl[i]] << endl;
            if (tl[i] != i && tr[tl[i]] == i + 1)
            {
                cl += dl[tl[i]];
                l = max(l, tl[i] + 1);
            }
            // clog << ' ' << l << ' ' << r << endl;
            cl += r - l + 1;
        }
        { // calc cr
            int l = max(tll[i], i + 2), r = min(tlr[i], tr[i + 1]);
            if (tr[i + 1] != i + 1 && tl[tr[i + 1]] == i)
            {
                cr += dr[tr[i + 1]];
                r = min(r, tr[i + 1] - 1);
            }
            cr += r - l + 1;
        }
        // clog << i << ' ' << cl << ' ' << cr << endl;
        res += cl * cr;
    }
    cout << res << '\n';
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> Tid >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
