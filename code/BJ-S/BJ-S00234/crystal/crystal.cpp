#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005];
__int128 pre[500005];
int pos;
int ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    pre[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] + 1ll * (a[i] - a[i - 1]) * (i - 1 - pos);
        while (pre[i] > m && pos <= n)
        {
            pre[i] -= a[i] - a[pos];
            pos++;
        }
        if (pre[i] <= m)
        {
            ans = max(ans, i - pos);
        }
    }
    cout << ans << endl;
    return 0;
}