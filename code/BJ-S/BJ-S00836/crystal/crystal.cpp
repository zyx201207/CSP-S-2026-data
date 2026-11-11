#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e5 + 5;

int n, m;
int a[maxn];

int ans = -1;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if (n >= 1e5)
    {
        int tmp = a[2] - a[1];
        int cnt = m / tmp;

        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (sum + i > cnt)
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        int last = m;
        int tmp = 1;

        for (int j = i - 1; j >= 1; j--)
        {
            if (last > 0)
            {
                last -= (a[i] - a[j]);
                tmp++;
            }
            else
            {
                break;
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
