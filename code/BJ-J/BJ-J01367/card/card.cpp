#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    long long n, m, a[500005], b[500005];
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i; j <= n; j++)
        {
            for (long long k = j; k <= n; k++)
            {
                    if (a[i] == a[j])
                    {
                        for (long long l = j; l < k; l++)
                        {
                            a[k] = 0;
                        }
                    }
            }
        }
        for (long long i = 1; i <= m; i++)
        {
            b[a[i]]++;
        }

    }
    for (long long i = 1; i <= m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
