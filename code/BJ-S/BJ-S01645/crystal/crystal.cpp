#include <bits/stdc++.h>
using namespace std;
#define il inline
typedef long long ll;
const int N = 5e5 + 10;
ll a[N], s[N], m;
int n;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;++i) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(int i = 1;i <= n;++i)
    {
        int l = 1, r = i;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if((i - mid + 1ll) * a[i] - s[i] + s[mid - 1] <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}
