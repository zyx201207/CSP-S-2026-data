#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;

int n, m, a[N], sa[N];

inline int f(int l, int r)
{
    return a[r + 1] * (r - l + 1) - (sa[r] - sa[l - 1]);
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        sa[i] = sa[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; )
    {
        int l = 1, r = i;   
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (f(mid, i - 1) <= m)
                r = mid;
            else 
                l = mid + 1;
        }
        int sum = (i - l + 1), cur = i;
        while (cur + 1 <= n && a[cur + 1] == a[i]) cur++, sum++;
        ans = max(ans, sum);
        i = cur + 1;
    }
    cout << ans << "\n";
    return 0;
}