#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6 + 10;

int c, T;
int n, d;
int a[N];

bool check(int l, int r)
{
    int dis = a[r] - a[l];

    if(dis <= d)
    {
        return false;
    }

    int cnt = 0;

    for(int i = l + 1; i < r; i++)
    {
        int d1 = a[i] - a[l];
        int d2 = a[r] - a[i];

        if(max(d1, d2) <= d)
        {
            cnt++;
        }
    }

    return cnt == 2;
}

void solve()
{
    cin >> n >> d;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if(d == 1)
    {
        cout << 0 << '\n';

        return ;
    }

    int ans = 0;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(check(j, i))
            {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

signed main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}