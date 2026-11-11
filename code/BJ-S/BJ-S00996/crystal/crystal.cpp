#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0, l = 1;
long long m, a[500010], sum = 0;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int r = 1; r <= n; r++)
    {
        sum += 1LL * (r - 1 - l + 1) * (a[r] - a[r - 1]);
        while (l <= r && sum > m)
        {
            sum -= (a[r] - a[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
