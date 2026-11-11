#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 5;
int n, ans;
long long m, p[MAX], pref[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + p[i];
    for (int r = 1, l = 1; r <= n; ) {
        if (p[r] * (r - l) - (pref[r - 1] - pref[l - 1]) <= m) ans = max(ans, r - l + 1), r++;
        else l++;
    }
    cout << ans << '\n';
    return 0;
}
