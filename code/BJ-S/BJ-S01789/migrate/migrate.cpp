#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int a[N], l[N], r[N], f[N][2][2], cnt[N];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n+3; i++)
        {
            f[i][1][1] = f[i][1][2] = f[i][2][1] = 0;
            cnt[i] = 0;
        }
        int p = 1;
        for (int i = 1; i <= n; i++)
        {
            while (a[i] - a[p] > d) p++;
            l[i] = p;
//            cout << l[i] << " ";
        }
        p = n;
        for (int i = n; i >= 1; i--)
        {
            while (a[p] - a[i] > d) p--;
            r[i] = p;
//            cout << r[i] << " ";

        }
//        cout << "\n";
        // First, The a[i]-a[i-1] <= d Gen
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
//            f[i][1][1]++;
            if (l[i] == i)
            {
                cnt[r[i]]++;
                continue;
            }
            f[i][1][1] += cnt[i];
            f[i][1][2] += cnt[i+1];
//            cout << i << " " << f[i][1][1] << " " << f[i][1][2] << " " << f[i][2][1] << "\n";
            if (r[l[i]] == i) f[i][1][1] += f[l[i]][1][1];
//            cout << i << " " << f[i][1][1] << " " << f[i][1][2] << " " << f[i][2][1] << "\n";
            if (r[l[i]] == i+1) f[i][1][2] += f[l[i]][1][1];
//            cout << i << " " << f[i][1][1] << " " << f[i][1][2] << " " << f[i][2][1] << "\n";
            if (r[l[i]] == i) f[i][2][1] += f[l[i]][2][1];
            if (l[i] < i-1 && r[l[i]] == i && r[l[i]+1] == i) f[i][2][1] += f[l[i]][1][2];
//            cout << i << " " << f[i][1][1] << " " << f[i][1][2] << " " << f[i][2][1] << "\n";
            ans += f[l[i]][2][1] + (l[i] < i-1) * f[l[i]][1][2];
            cnt[r[i]]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
