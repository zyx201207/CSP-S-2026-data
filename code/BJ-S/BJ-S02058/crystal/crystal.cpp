#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[500010], ans;

void insert()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void work()
{
    insert();
    sort(a + 1, a + n + 1);
    for(int i = 1, j = 0; i <= n; i++)
    {
        while(j < n && (a[j + 1] - a[j]) * (j - i + 1) <= m)
            m -= (a[j + 1] - a[j]) * (j - i + 1), j++;
        ans = max(ans, j - i + 1);
        m += a[j] - a[i];
    }
    cout << ans << '\n';
}

signed main()
{
    freopen("crystal.out", "w", stdout);
    freopen("crystal.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}