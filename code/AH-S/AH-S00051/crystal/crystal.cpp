#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace usr
{
    const ll N = 5e5 + 5;
    ll a[N];
    ll n, m, ans;
    void solve(ll cas)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        a[0] = a[1];
        for (ll l = 1, r = 1, s = 0; r <= n; r++)
        {
            s += (r - l) * (a[r] - a[r - 1]);
            while (s > m)
            {
                s -= a[r] - a[l];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
    void main()
    {
        freopen("crystal.in", "r", stdin);
        freopen("crystal.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        // -Wall -Wextra -fsanitize=address,undefined
        ll T = 1, cas = 0;
        // cin >> T;
        // cin >> cas;
        while (T--) solve(cas);
    }
};
int main()
{
    usr::main();
    return 0;
}