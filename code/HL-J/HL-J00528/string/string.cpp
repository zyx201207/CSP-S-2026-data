#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = (int)2e5 + 5;
int n, a[MAXN], ans, j = 0, m;
char c[MAXN];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        m += a[i];
    }
    string s(m, 0);
    for (int i = 1; i <= n; i++)
    {
        s[j] = c[i];
        j += a[i];
    }
    for (int i = 1; i < m; i++)
        if (! (s[i] >= 'a' && s[i] <= 'z')) s[i] = s[i - 1];
    for (int i = 0; i < (int)s.size() / 2; i++)
        if (s[i] != s[(int)s.size() - 1 - i])
            ans++;
    cout << ans;
    return 0;
}
