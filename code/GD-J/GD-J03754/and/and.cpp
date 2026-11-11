#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[200010][32];
int vis[200010];

int mx_bit;

int ans;

int flag;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        int bit = 0;
        while (x)
        {
            if ((x & 1) == 1)
                a[i][bit] = 1;
            x >>= 1;
            bit++;
        }
        mx_bit = max(mx_bit, bit);
    }

    int now = 0;

    for (int bit = mx_bit - 1; bit >= 0; bit--)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i][bit] == 1 && (flag == 0 || vis[i] == 1))
                sum++;
        }
        if (sum >= m)
        {
            now += (1 << bit);
            ans = max(ans, now);
            if (flag == 0)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (a[i][bit] == 1)
                        vis[i] = 1;
                }
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    if (a[i][bit] == 1 && vis[i] == 1)
                        vis[i] = 1;
                }
            }
            flag = 1;
        }
    }
    cout << ans;
    return 0;
}
