#include <bits/stdc++.h>
using namespace std;
long long n, m, cd, sum = 0, ans = 0, a[10000010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum = min(sum, a[i + 1] - a[i]);
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
        {
            if (sum == a[i + 1] - a[i])
            {
                if (m >= ((a[i + 1] - a[i]) * (ans + 1)))
                {
                    m -= (a[i + 1] - a[i]) * (ans + 1);
                    for (int k = i; k <= i + ans + 1; k++) a[k] += (a[i + ans + 1 + 1] - a[i + ans + 1]);
                    ans += (ans + 1);
                }
                continue;
            }
        }
    cout << ans;
    return 0;
}
