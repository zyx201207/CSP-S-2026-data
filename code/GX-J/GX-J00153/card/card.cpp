#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long b[500005];
long long cnt[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    int cnt = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; x++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cnt[a[j]]++;
            if (cnt[a[j]] == 2)
            {
                for (int k = 1; k <= m; k++)
                {
                    if (cnt[k] == 0)
                    {
                        cnt[k]--;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << cnt[i];
    }
    return 0;
}
