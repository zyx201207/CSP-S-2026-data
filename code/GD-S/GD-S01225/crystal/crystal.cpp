#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
long long a[10005], b[10005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        if (b[a[i]] == n)
        {
            cout << n;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        while (m > 0)
        {
            int s = b[a[i]];
            for (int j = 1; j <= n-i; j++)
            {

                if (m -= b[a[i]+j] >= 0)
                {
                    s += b[a[i]+j];
                }
            }
            ans = max(ans, s);
        }
    }
    cout << ans;
    return 0;
}
