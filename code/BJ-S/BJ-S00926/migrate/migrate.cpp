#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 10;
int n, m, a[maxn], num[maxn], cnt[maxn];
pair<int, int> q[maxn];
signed main ()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T, C;
    cin >> C >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++) num[j] = 0;
            int l = 1, r = 0;
            q[++r] = make_pair(i, 0);
            cnt[i] = 1;
            num[0]++;
            for (int j = i + 1; j <= n; j++)
            {
                while (l <= r && a[j] - a[q[l].first] > m)
                {
                    num[q[l].second] -= cnt[q[l].first];
                    l++;
                }
                if (l > r) break;
                int t = q[l].second;
                cnt[j] = num[t];
                if (cnt[j] == 2)
                {
                    if (n <= 5e3) ans++;
                    else ans += n - j + 1;
                }
                while (l <= r && q[r].second > t + 1)
                {
                    num[q[r].second] -= cnt[q[r].first];
                    r--;
                }
                q[++r] = make_pair(j, t + 1);
                num[t + 1] += cnt[j];
            }
            if (n > 5e3)
            {
                cout << ans << '\n';
                break;
            }
        }
        if (n <= 5e3) cout << ans << '\n';
    }
    return 0;
}
