#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500100], b[500100];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    long long flag = 1, ans = n;
    while (flag == 1 && ans > 0)
    {
        if (a[ans] * (ans - 1) - b[ans - 1] <= m) flag = 0;
        else ans--;
    }
    cout << ans << endl;
    return 0;
}
