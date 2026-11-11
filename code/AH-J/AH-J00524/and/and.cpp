#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long maxn = -1000005;
    if (m == 2)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((a[i] & a[j]) > maxn)
                {
                    maxn = (a[i] & a[j]);
                }
            }
        }
        cout << maxn;
        return 0;
    }
    if (m == 3)
    {
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if ((a[i] & a[j] & a[k]) > maxn)
                    {
                        maxn = (a[i] & a[j] & a[k]);
                    }
                }
            }
        }
        cout << maxn;
        return 0;
    }
    if (m == 4)
    {
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < k - 1; j++)
                {
                    for (int x = k + 1; x < n; x++)
                    {
                        if ((a[i] & a[j] & a[k] & a[x]) > maxn)
                        {
                            maxn = (a[i] & a[j] & a[k] & a[x]);
                        }
                    }
                }
            }
        }
        cout << maxn;
        return 0;
    }
    if (m == 5)
    {
        for (int i = 0; i < n - 4; i++)
        {
            for (int j = i + 1; j < n - 3; j++)
            {
                for (int k = j + 1; k < k - 3; j++)
                {
                    for (int x = k + 1; x < n - 1; x++)
                    {
                        for (int y = x + 1; y < n; y++)
                        {
                            if ((a[i] & a[j] & a[k] & a[x] & a[y]) > maxn)
                            {
                                maxn = (a[i] & a[j] & a[k] & a[x] & a[y]);
                            }
                        }
                    }
                }
            }
        }
        cout << maxn;
        return 0;
    }
    return 0;
}
