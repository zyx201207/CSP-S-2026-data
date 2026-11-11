#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 5e5+10;
int n, m;
int a[NR];
int d[NR], s[NR];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if((i - mid) * a[i] - s[i - 1] + s[mid - 1] <= m)
            {
                r = mid;
            }
            else l = mid + 1;
        }
//        cout << l << " ";
        ans = max(ans, i - l + 1);
    }
//    cout << "\n";
    cout << ans << "\n";
    return 0;
}
