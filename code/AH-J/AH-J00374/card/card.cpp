#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], num[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long ju[500005] = {}, cnt = 0;

        for (int j = i; j <= n; j++)
        {
            cnt++;
            ju[cnt] = a[j];
            for (int l = 1; l <= cnt - 1; l++)
            {
                if (ju[l] == ju[cnt])
                {
                    for (int f = l; f <= cnt - 1; f++)
                    {
                        ju[f] = 0;
                    }
                }
            }
        }
        for (int j = 1; j <= cnt; j++)
        {
            if(ju[j] != 0)
            {
                num[ju[j]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}
