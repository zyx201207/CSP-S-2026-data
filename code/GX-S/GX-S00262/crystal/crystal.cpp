#include <bits/stdc++.h>
using namespace std;
long long n, m, x, a[500005], pos, cnt, maxn = 0, b[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos = 1;
        cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            b[pos] = abs(a[i] - a[j]);
            pos++;
        }
        sort(b + 1, b + n + 1);
        x = m;
        for (int j = 1; j <= pos - 1; j++)
        {
            if (x - b[j] >= 0)
            {
                x -= b[j];
                cnt++;
            }
        }
        maxn = max(cnt, maxn);
    }
    cout << maxn;
    return 0;
}
