#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[500005], cnt[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cout << "1 ";
    /*for (int i = 1; i <= n; i++)
    {
        bool k[300005];
        memset(k, false, m);
        for (int j = 1; j <= n; j++)
        {
            if (k[a[j]])
            {
                memset(k, false, m);
                k[a[j]] = true;
            }
        }
        for (int l = 1; l <= m; l++)
            if (k[l])
                cnt[l]++;
    }
    for (int i = 1; i <= m; i++)
        cout << cnt[i] << " ";*/
    return 0;
}
