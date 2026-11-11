#include <bits/stdc++.h>
using namespace std;
long long a[500005], n, m;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long ans = 0, sum = 0;
    for (long long i = 1, j = 1; i <= n && j <= n;)
    {
        while ((j <= n) && (sum + (j - i) * (a[j] - a[j - 1]) <= m))
        {
            sum += (j - i) * (a[j] - a[j - 1]);
            j++;
        }
        ans = max(ans, j - i);
        sum -= (a[j - 1] - a[i]);
        i++;
    }
    cout << ans << '\n';
    return 0;
}