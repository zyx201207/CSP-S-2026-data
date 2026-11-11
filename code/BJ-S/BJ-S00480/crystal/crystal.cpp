#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n, m, a[500005], ans;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll l = 1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (i - l) * (a[i] - a[i - 1]);
        while (cnt > m) cnt -= (a[i] - a[l]), l++;
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}
