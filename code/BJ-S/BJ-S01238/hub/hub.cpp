//#define int long long
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int n, k, C, T, a[N], t[N];
int d(int x)
{
    if ( t[x] == x ) return 1;
    return d(t[x]) + 1;
}
int f(int x)
{
    if ( t[x] == x ) return x;
    return f(t[x]);
}

signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin >> C >> T;
    while (T--)
    {
        int ans;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            t[i] = i;
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            t[v] = u;
            ans = max(ans, d(u));
        }
        cout << ans / (k - 1) << endl;
    }

    return 0;
}
