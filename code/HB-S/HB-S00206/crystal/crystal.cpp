#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005], d[500005];

void solve1()
{
    int maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        int mm = m, cnt = 0;
        memset(d, 0, sizeof(d));
        for (int j = 1; j <= n; j++)
            d[j] = abs(a[j] - a[i]);
        sort(d + 1, d + n + 1);
        for (int j = 1; j <= n; j++)
        {
            if (mm - d[j] >= 0)
            {
                cnt++;
                mm -= d[j];
            }
            else
            {
                maxn = max(maxn, cnt);
                break;
            }
        }
    }
    cout << maxn;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    long long cha, ans = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i >= 3 && (a[i] - a[i - 1]) != cha)
            flag = false;
        cha = a[i] - a[i - 1];
    }
    if (flag)
    {
        long long mid = n / 2;
        long long l = mid, r = mid;
        while (l > 0 && r < n)
        {
            if (m - cha > 0) l--, ans++;
            if (m - cha > 0) r++, ans++;
        }
        cout << ans;
        return 0;
    }
    if (n <= 16) solve1();
    return 0;
}
