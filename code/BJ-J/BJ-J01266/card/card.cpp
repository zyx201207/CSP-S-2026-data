#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], cnt[M], l[M], r[M], ans[M];
bool spc;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    spc = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) spc = 0;
        cnt[a[i]]++;
    }
    if (spc)
    {
        int now = a[1];
        for (int i = 1; i <= n; i++)
        {
            if (now != a[i]) r[a[i - 1]] = i - 1, now = a[i];
        }
        r[a[n]] = n;
        for (int i = 1; i <= m; i++) cout << r[i] << ' ';
    }
    else
    {
        for (int i = n; i >= 1; i--)
        {
            if (!r[a[i]]) r[a[i]] = i;
        }
        for (int t = 1; t <= n; t++)
        {
            for (int i = t; i <= n; i++)
            {
                if (cnt[a[i]] == 1)
                {
                    ans[a[i]]++;
                    continue;
                }
                ans[a[i]]++;
                i = r[a[i]];
            }
            cnt[a[t]]--;
        }
        for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    }
    return 0;
}
