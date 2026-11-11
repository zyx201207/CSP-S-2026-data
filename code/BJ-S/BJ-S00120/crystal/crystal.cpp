#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = 1, sum = 0, ans = 0;
    while(l <= r && r <= n)
    {
        if(sum <= m) r++, sum += (r - l) * (a[r] - a[r - 1]);
        if(sum > m) l++, sum -= a[r] - a[l];
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
