#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n;
int m;
int a[N];
int pre[N];
int ans;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + a[i];

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] * ans - pre[i] + pre[i - ans] > m)
            continue;

        for (int j = i - ans, k = 1; j >= 1; --j, ++k)
        {

            if ((a[i] * (ans + k) - pre[i] + pre[j - 1]) <= m)
                ++ans;
            else
                break;
        }
    }

    printf("%lld", ans);

    return 0;
}