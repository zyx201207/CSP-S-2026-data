#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, a[200005];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

    }
    if (m == 1)
    {
        sort(a + 1, a + n + 1, cmp);
        cout << a[1];
    }
    else if (m == 2)
    {
        int maxn = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                maxn = max(maxn, a[i] & a[j]);
            }
        }
        cout << maxn;
    }
    else if (m == n)
    {
        sort(a + 1, a + n + 1, cmp);
        int ans = a[1];
        for (int i = 2; i <= m; i++)
            ans &= a[i];
        cout << ans;
    }
    else// if (m == n - 1)
    {
        int minn, max0 = 0xff;
        for (int i = 1; i <= n; i++)
        {
            int t = a[i], cnt = 0;
            while (t != 0)
            {
                if (t & 1 == 0)
                    cnt++;
                t >>= 1;
            }
            if (cnt > max0)
            {
                max0 = cnt;
                minn = a[i];
            }
        }
        int ans = a[1];
        for (int i = 2; i <= m; i++)
        {
            if (a[i] != minn)
                ans &= a[i];
        }
        cout << ans;
    }
    return 0;
}
