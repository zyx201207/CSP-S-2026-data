#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int in[300005];
int ans[300005];
int t[500005];
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
        int pos = 0;
        for (int j = 0; j <= 100005; j++)
        {
            in[j] = 0;
        }
        for (int j = i; j <= n; j++)
        {
            if (in[a[j]] != 0)
            {
                for (int k = in[a[j]] + 1; k <= pos; k++)
                {
                    in[t[k]] = 0;
                    t[k] = 0;
                }
                pos = in[a[j]];
            }
            else
            {
                pos++;
                in[a[j]] = pos;
                t[pos] = a[j];
            }
        }
        for (int j = 1; j <= m; j++)
        {
            if (in[j] != 0)
            {
                ans[j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
