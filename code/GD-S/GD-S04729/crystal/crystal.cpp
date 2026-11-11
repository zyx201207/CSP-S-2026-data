#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], tot, ans, amin, cnt;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1, j = 0; i <= n; i++)
    {
        tot += a[i];
        cnt++;
        while (a[i] * cnt - tot > m)
        {
            j++;
            tot -= a[j];
            cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
