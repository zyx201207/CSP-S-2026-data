#include <bits/stdc++.h>
using namespace std;

int a[200005];
int ans = 0;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == m)
    {
        for (int i = 1; i <= n; i++)
        {
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, a[i]);
        }
        cout << ans;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    return 0;
}
