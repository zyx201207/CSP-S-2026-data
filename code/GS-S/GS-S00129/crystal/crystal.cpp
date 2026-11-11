#include <iostream>
#include <algorithm>

long long a[500000], b[500000];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, ans = 1;
    long long m;
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);
    std::sort(a, a + n);
    for (int i = 1; i < n; ++i)
        b[i] = a[i] - a[i - 1];
    for (int i = n - 1; ~i; --i)
        a[i] -= a[0];
    long long c = b[1];
    for (int l = 1, r = 1; l < n; ++l)
    {
        while (r < n && c + b[r + 1] * (r - l + 2) <= m) ++r, c += b[r] * (r - l + 1);
        ans = std::max(ans, r - l + 2);
        c -= a[r] - a[l - 1];
    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
