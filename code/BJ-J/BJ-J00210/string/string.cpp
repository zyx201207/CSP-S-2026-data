#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = "";
    long long len = 0;
    for (int i = 1; i <= n; ++i)
    {
        int m;
        string a;
        cin >> m >> a;
        for (int i = 1; i <= m; ++i)
        {
            s += a;
        }
        len += 1ll * m;
    }
    long long ans = 0;
    for (int i = 0; i < len / 2; ++i)
    {
        if (s[i] != s[len - i - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
