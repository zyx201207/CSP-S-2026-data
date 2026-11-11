#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[500005], cot, lst[500005], b[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        cot = j - 1;
        memset(lst, 0, sizeof(lst));
        memset(b, 0, sizeof(b));
        for (int i = j; i <= n; i++)
        {
            if (lst[a[i]] == 0)
            {
                cot++;
                lst[a[i]] = i;
                b[cot] = a[i];
            }
            else
            {
                cot = lst[a[i]];
            }
        }
        for (int i = j; i <= cot; i++)
        {
            cnt[b[i]]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}