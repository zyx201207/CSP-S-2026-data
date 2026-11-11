#include <bits/stdc++.h>
using namespace std;

long long n, a[200010], sa[200010], cur = 0, ans = 0, maxai = 0;
char c[200010], s[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        maxai = max(maxai, a[i]);
    }
    if (n * maxai <= 200000)
    {
        for (int i = 1; i <= n; i++)
        {
            while (a[i]--)
            {
                s[++cur] = c[i];
            }
        }
        for (int j = cur / 2 + 1; j <= cur; j++)
        {
            ans += (s[j] != s[cur - j + 1]);
        }
    }
    else
    {
        sa[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            sa[i] = sa[i - 1] + a[i];
        }
        cur = sa[n];
        for (int i = 1; i <= n; i++)
        {
            long long l = sa[i - 1] + 1, r = sa[i];
            int pos = lower_bound(sa + 1, sa + n + 1, cur - l + 1) - sa;
            if (r <= cur / 2 && c[i] != c[pos]) ans += r - l + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
