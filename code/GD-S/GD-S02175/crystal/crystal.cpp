#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n, m, a[500100], d[500100];
ll ans = 0;
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
    ll l = 1, r = 1; // [l, r]
    ll cost = 0;
    for (; r <= n; r++)
    {
        cost += (r - l) * (a[r] - a[r - 1]);
        if (cost > m)
        {
            cost -= a[r] - a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}
// 居然有 VSCode，好通透啊。
// MKMIFYM