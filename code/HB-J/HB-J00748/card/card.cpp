#include <bits/stdc++.h>
#define Trick 1
#define Treat 1
using namespace std;
int n, m;
int a[500010], w[300010], cnt[300010];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (m == 1)
    {
        cnt[1] = n;
    }
    else if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != a[n] && (Trick || Treat))
            {
                cnt[3-a[i]]++;
            }
            cnt[a[i]]++;
        }
    }
    else if (n <= 500)
    {
        for (int i = 1; i <= n; i++)
        {
            memset(w, -1, sizeof w);
            for (int j = i; j <= n; j++)
            {
                if (w[a[j]] != -1)
                {
                    for (int k = w[a[j]]; k < j; k++)
                    {
                        w[a[k]] = -1;
                    }
                }
                w[a[j]] = j;
            }
            for (int j = 1; j <= m; j++)
            {
                if (w[j] != -1)
                {
                    cnt[j]++;
                }
            }
        }
    }
    else
    {
        a[0] = 1;
        for (int i = 1; i <= n ; i++)
        {
            if (a[i] != a[i-1])
            {
                w[a[i-1]] = i - 1;
                cnt[a[i-1]] = w[a[i-1]];
            }
        }
        cnt[m] = n;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", cnt[i]);
    }
    return 0;
}