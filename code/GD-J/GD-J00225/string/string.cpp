# include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const int N = 2e5 + 5;
ll n, a[N], ans = 0;
char c[N];

int main ()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    ios :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);

    cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i] >> c[i]; }
    int l = 1, r = n; if (n == 1) { cout << 0; return 0; }
    while (l < r)
    {
        if (c[l] == c[r])
        {
            if (a[l] < a[r])
            {
                a[r] -= a[l];
                l ++;
            }
            else if (a[l] > a[r])
            {
                a[l] -= a[r];
                r --;
            }
            else
            {
                l ++;
                r --;
            }
        }
        else
        {
            if (a[l] < a[r])
            {
                ans += a[l];
                a[r] -= a[l];
                l ++;
            }
            else if (a[l] > a[r])
            {
                ans += a[r];
                a[l] -= a[r];
                r --;
            }
            else
            {
                ans += a[l];
                l ++;
                r --;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}