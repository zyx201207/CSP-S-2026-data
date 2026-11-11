#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[500005], s[500005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
        int l = 1, r = i, p = i;
        while (l <= r){
            int mid = (l + r) / 2;
            if (s[i] - s[mid - 1] + m >= a[i] * (i - mid + 1))
                p = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        ans = max(ans, i - p + 1);
    }
    cout << ans << endl;
    return 0;
}
