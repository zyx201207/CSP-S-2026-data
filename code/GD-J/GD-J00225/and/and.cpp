# include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const int N = 2e5 + 5;
ll n, m, a[N], cnt[N], ans;
bool vis[N];

int main ()
{
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    ios :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 29; j >= 0; j--)
        {
            if (a[i] >> j & 1ll)
            {
                cnt[j] ++;
            }
        }
        vis[i] = 1;
    }

    for (int i = 29; i >= 0; i--)
    {
        if (cnt[i] >= m)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!(a[j] >> i & 1ll) && vis[j])
                {
                    vis[j] = 0;
                    for (int k = 29; k >= 0; k--)
                    {
                        if (a[j] >> k & 1ll)
                        {
                            cnt[k] --;
                        }
                    }
                }
            }
            ans += (1ll << i);
        }
    }
    
    cout << ans << "\n";

    return 0;
}