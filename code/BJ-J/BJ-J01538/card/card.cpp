#include <bits/stdc++.h>

using namespace std;

const int maxn = 500007;

int a[maxn], ans[maxn];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    for (int i = n; i >= 1; i -- )
        if (ans[a[i]] == 0)
            ans[a[i]] = i;

    for (int i = 1; i <= m; i ++ ) cout << ans[i] << ' ';

    return 0;
}
