#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10;

int n, m;
int a[N];
int sum[N];
int sum0[N];

signed main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        int t = a[i] - a[i - 1];

        sum0[i] = sum0[i - 1] + t;
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++)
    {
        int t = a[i] - a[i - 1];

        sum[i] = sum[i - 1] + (i - 1) * t;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int L = 1, R = i;

        int res = i;
        int f = 0;

        while(L <= R)
        {
            int mid = (L + R) >> 1;

            int s = sum[i] - sum[mid - 1] - (mid - 1) * (sum0[i] - sum0[mid - 1]);

            if(s <= m)
            {
                f = 1;

                res = mid;

                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }

        if(f)
        {
            ans = max(ans, i - res + 1);
        }
    }

    cout << ans << '\n';

    return 0;
}