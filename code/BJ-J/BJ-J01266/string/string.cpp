#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N], ans;
char c[N];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    int l = 1, r = n, cntl = a[1], cntr = a[n];
    while (true)
    {
        if (cntl == cntr)
        {
            ans += !(c[l] == c[r]) * cntl;
            l++, r--;
            if (l >= r) break;
            cntl = a[l], cntr = a[r];
        }
        else if (cntl > cntr)
        {
            ans += !(c[l] == c[r]) * cntr;
            cntl -= cntr;
            r--;
            if (l >= r) break;
            cntr = a[r];
        }
        else
        {
            ans += !(c[l] == c[r]) * cntl;
            cntr -= cntl;
            l++;
            if (l >= r) break;
            cntl = a[l];
        }
    }
    cout << ans;
    return 0;
}
