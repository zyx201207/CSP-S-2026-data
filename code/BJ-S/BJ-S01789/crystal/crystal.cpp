#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], s[N];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    int p = 1, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[i]*(i-p+1) - (s[i] - s[p-1]) > m) p++;
        ans = max(ans, i-p+1);
    }
    cout << ans;
    return 0;
}

