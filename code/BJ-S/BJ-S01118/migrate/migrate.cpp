#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
using namespace std;

typedef long long ll;

const int N = 2e6;
const int N1 = 5e3;

int c;

int n;

ll d, x[N + 5];

int f[N1 + 5];

ll g[N1 + 5], pre[N1 + 5];

void solve()
{
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x[i];
    }
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    if (c <= 10)
    {
        int ans = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            f[i] = 0;
            g[i] = 1;
            pre[i] = 1;
            pre[i - 1] = 0;
            for (int j = i + 1 ; j <= n ; j++)
            {
                int k = lower_bound(x + i, x + n + 1, x[j] - d) - x;
                f[j] = f[k] + 1;
                int kk = upper_bound(f + k, f + j + 1, f[k]) - f - 1;
                g[j] = pre[kk] - pre[k - 1];
                pre[j] = pre[j - 1] + g[j];
                if (g[j] == 2) ans++;
            }
        }
        cout << ans << '\n';
        return;
    }
    if (11 <= c && c <= 12)
    {
        int ans = 0;
        ll k = d / (x[2] - x[1]);
        if (k <= 1)
        {
            cout << "0\n";
            return;
        }
        for (int i = 1 ; i <= n ; i++)
        {
            if (i + k + k - 1 <= n) ans++;
        }
        cout << ans << '\n';
        return;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T;
    cin >> c >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
