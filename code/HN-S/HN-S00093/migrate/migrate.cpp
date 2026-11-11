#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, T, n;
ll d, a[N], l[N], r[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while(T--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];
        l[0] = 1;
        for(int i = 1, res; i <= n; i++) 
        {
            res = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
            if(res >= i) l[i] = 1;
            else l[i] = lower_bound(a + 1, a + n + 1, a[res + 1] - d - 1) - lower_bound(a + 1, a + n + 1, a[res] - d) + i - res + 1;
        }
        r[n + 1] = 0;
        for(int i = n, res; i >= 1; i--)
        {
            res = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
            if(res <= i) r[i] = 1;
            else r[i] = upper_bound(a + 1, a + n + 1, a[res] + d) - upper_bound(a + 1, a + n + 1, a[res - 1] + d + 1) + res - i + 1;
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = max(i + 2, (int)(upper_bound(a + 1, a + n + 1, a[i] + d) - a)), res; j <= n; j++)
            {
                res = upper_bound(a + 1, a + n + 1, a[i] + d) - lower_bound(a + 1, a + n + 1, a[j] - d);
                if(res == 2) ans += 1ll * (a[i + 1] - a[i - 1] > d ? l[i] : 1) * (a[j + 1] - a[j - 1] > d ? r[j] : 1);
                else if(res < 2) break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}