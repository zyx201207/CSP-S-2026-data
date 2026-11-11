#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[300005], c[300005], s;
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
        memset(b, 0, sizeof(b));
        for (int j = i; j <= n; j++)
        {
            if (b[a[j]] == 0)
            {
                b[a[j]] = 1;
            }
            else
            {
                for (int k = s; k < j; k++)
                {
                    b[a[k]] = 0;
                }
                b[a[j]] = 1;
                s = j;
            }
        }
        for (int j = s; j <= n; j++)
        {
            c[a[j]]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}
