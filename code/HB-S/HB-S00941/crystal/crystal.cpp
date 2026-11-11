#include <bits/stdc++.h>

using namespace std;

const long long maxn = 5e5 + 10;

long long n, m;
long long a[maxn];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long i, l, r;

    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    long long ans = 0, now = 0;
    l = r = 1;
    for (l = 1; l <= n; l++)
    {
        for (; r <= n; r++)
        {
            if (now + a[l] - a[r] > m)
            {
                break;
            }
            ans = max(ans, r - l + 1);
            now += a[l] - a[r];
        }
        if (l != n) now -= (r - l) * (a[l] - a[l + 1]);
    }

    cout << ans;

    return 0;
}
