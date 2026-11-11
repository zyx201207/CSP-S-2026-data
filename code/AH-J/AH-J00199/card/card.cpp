#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    int b[m + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        b[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int c[n+1];
        for (int j = i; j <= n;j++)
        {
            c[j] = a[j];
            for (int k = j - 1; k >= i; k--)
            {
                if (c[j] == c[k])
                {
                    for (int l = k; l < j;l++)
                    {
                        c[l] = 0;
                    }
                    break;
                }
            }
        }
        for (int q = i; q <= n; q++)
        {
            b[c[q]]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
