#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500005], tot, ans;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d", &n);
    scanf("%lld", &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--)
    {
        int r = i, cnt = 1, tmp = 0;
        while (r > 1)
        {
            if ((a[r - 1] > a[i]) || (a[i] - a[r - 1] + tmp > m))
                break;
            r--;
            tmp += (a[i] - a[r]);
            cnt++;
        }
        ans = max((long long)(cnt), ans);
    }
    printf("%lld\n", ans);
    return 0;
}