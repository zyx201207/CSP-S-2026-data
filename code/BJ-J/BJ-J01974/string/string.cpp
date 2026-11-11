#include <bits/stdc++.h>
#define int long long
using namespace std;

int w[1000005];
char c[1000005];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> c[i];
    }
    int l = 1,r = n;
    int ans = 0;
    while (l <= r)
    {
        if (w[l] <= 0)
        {
            l++;
        }
        if (w[r] <= 0)
        {
            r--;
        }
        if (c[l] != c[r]) ans += min(w[l],w[r]);
        int o = w[l],p = w[r];
        w[l] -= min(o,p);
        w[r] -= min(o,p);
       // cout << l << " " << r << " " << ans << endl;
       // cout << w[l] << " " << w[r] << endl;
    }
    cout << ans;
    return 0;
}
