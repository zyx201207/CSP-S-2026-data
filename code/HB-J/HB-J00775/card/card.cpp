#include <bits/stdc++.h>
using namespace std;

int n,m,c[500001],tot[300001],s;


int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    memset(tot, 0, sizeof(tot));
    scanf ("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &c[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            s = c[j];
            for (int k = n; k > j; k--)
            {
                if (s == c[k])
                {
                    j = k;
                    break;
                }
            }
            tot[s]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf ("%d", tot[i]);
        if (i < m)
        {
            printf (" ");
        }
    }
    return 0;
}
