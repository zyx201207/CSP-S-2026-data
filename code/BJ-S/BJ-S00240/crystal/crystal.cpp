#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cnt, ans, t;
bool flag1, flag2;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    cin >> a[1] >> a[2];
    if (a[1] != 1 || a[2] != 2)
    {
        flag1 = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != i)
        {
            flag1 = 1;
        }
        if (a[i] - a[i - 1] != a[2] - a[1])
        {
            flag2 = 1;
        }
    }
    sort(a + 1, a + 1 + n);
    if (flag1 == 0)
    {
        m *= 2;
        long long t = sqrt(m);
        if (t * (t + 1) <= m)
        {
            cout << t + 1 << endl;
            return 0;
        }
        cout << t << endl;
        return 0;
    }
    if (flag2 == 0)
    {
        long long d = a[2] - a[1];
        m *= 2;
        long long t = sqrt(m);
        for (long long i = t; i >= 0; i--)
        {
            if ((d + d * i) * i <= m)
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt = 1;
        t = m;
        for (int j = i - 1; j >= 1; j--)
        {
            t -= (a[i] - a[j]);
            if (t < 0)
            {
                break;
            }
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}