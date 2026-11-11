#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[500010], s[500010];
int ans;

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) > m) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        //cout << l << endl;
        ans = max(ans, i - l + 1);
    }
    cout << ans;
}
