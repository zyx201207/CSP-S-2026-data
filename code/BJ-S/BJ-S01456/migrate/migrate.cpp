#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n;
long long d;
long long a[N], ed, st, cnt = 0;

void dfs(int x, int step)
{
    if (x == ed)
    {
        if (step < st) st = step, cnt = 1;
        else if (step == st) cnt++;
        return;
    }
    for (int i = x + 1; x <= ed; ++i)
    {
        if (a[i] - a[x] > d) return;
        dfs(i, step + 1);
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        long long dis = 9e18;
        bool fl = true;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (dis == 9e18 && i == 2) dis = a[i] - a[i - 1];
            if (i > 1)
            {
                if (a[i] - a[i - 1] != dis) fl = false;
            }
        }
        if (fl)
        {
            long long dd = d / dis;
            if (dd != 2) cout << 0 << endl;
            else cout << max(n - 3, 0) << endl;
        }
        else
        {
            int ans = 0;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = i + 1; j <= n; ++j)
                {
                    cnt = 0;
                    ed = j;
                    st = 1e9;
                    dfs(i, 0);
                    //cout << i << " " << j << " "<< cnt << endl;
                    if (cnt == 2) ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
