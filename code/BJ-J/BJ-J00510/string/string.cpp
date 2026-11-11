#include <bits/stdc++.h>
#define ll long long
// #define endl "\n"
using namespace std;
ll n, a[200005], m;
char c[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        m += a[i];
    }
    ll l = 0, r = n + 1, cntl = 0, cntr = 0, ans = 0;
    while (cntl + cntr < m)
    {
        // cout << l << " " << r << " " << cntl << " " << cntr << " ";
        if (cntl <= cntr)
        {
            l++;
            // cout << "do l " << (c[l] != c[r]) * min(cntr - cntl, a[l]) << endl;
            ans += (c[l] != c[r]) * min(cntr - cntl, a[l]);
            cntl += a[l];
        }
        else
        {
            r--;
            // cout << "do r " << (c[l] != c[r]) * min(cntl - cntr, a[r]) << endl;
            ans += (c[l] != c[r]) * min(cntl - cntr, a[r]);
            cntr += a[r];
        }
    }
    // cout << l << " " << r << " " << cntl << " " << cntr << endl;
    cout << ans << endl;
    return 0;
}
/*
6
1 a
1 a
1 a
1 b
1 b
1 b
*/
