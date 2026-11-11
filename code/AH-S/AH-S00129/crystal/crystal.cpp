#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005];
ll s[500005];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a+n);
    for (int i = 1; i <= n; i++)
        s[i] = a[i] + a[i-1];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i-1, mid;
        while (l < r) {
            mid = (l+r)/2 + 1;
            if (mid * a[i] - (s[i-1] - s[i-m-1]) <= m)
                l = mid;
            else
                r = mid-1;
        }
        ans = max(r+1, ans);
    }
    cout << ans << endl;
    return 0;
}
