#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cnt[300005], ans, pos1[300005], pos2[500005], res;
bool flag = false;
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
        for (int k = i; k <= n; k++)
        {
            if (k == i) continue;
            else
            {
                if (pos1[a[k]] == 0)
                {
                    pos1[a[k]]++;
                    pos2[a[k]] = i;
                }
                else
                {
                    res = k - pos2[a[k]];
                    for (int j = pos2[a[k]]; j < k; j++)
                    {
                        a[j] = 0;
                    }
                }
            }
        }
        for (int k = 1; k <= n; k++)
        {
            if (a[k] != 0)
            {
                cnt[a[k]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (i == 1) cout << cnt[i] + 1 << " ";
        else cout << cnt[i] << " ";
    }
    return 0;
}
