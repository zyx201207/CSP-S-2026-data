#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
        if (i == n)
            cnt[a[i]] = n;
    }
    for (int i = 1; i <= m; ++i)
        cout << cnt[i] << " ";
    return 0;
}