#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 500005;
ll n, m, a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long sum = 0; int ans = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        while (sum > m) {
            sum -= a[r] - a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
        if (r < n) sum += (r - l + 1) * (a[r + 1] - a[r]);
    }
    cout << ans << '\n';
    return 0;
}