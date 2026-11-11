#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500005];
int x[300005];
int ans[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            x[j] = 0;
        for (int j = i; j <= n; j++)
        {
            if (x[a[j]])
            {
                for (int k = a[j]; k <= m; k++)
                    x[k] = 0;
            }
            x[a[j]]++;
        }
        for (int j = 1; j <= m; j++)
            ans[j] += x[j];
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    return 0;
}
