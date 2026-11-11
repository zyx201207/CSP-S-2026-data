#include <bits/stdc++.h>
using namespace std;

int n, m, maxn;
int a[200010][40], b[200010], f[200010];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
    {
        int t, k = 0;
        cin >> t;
        b[i] = t;
        while (t)
        {
            a[i][++k] = t % 2;
            t /= 2;
        }
        maxn = max(maxn, k);
    }
    int flag = 1;
    for (int i = maxn; i >= 1; i--)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == 1)
            {
                cnt++;
                f[j] = 0;
            }
            else
            {
                f[j] = 1;
            }
        }
        if (cnt >= m)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << 0;
        return 0;
    }
    int x = (1 << 31) - 1;
    for (int i = 1; i <= n; i++)
    {
        if (!f[i]) x &= b[i];
    }
    cout << x;
    return 0;
}
