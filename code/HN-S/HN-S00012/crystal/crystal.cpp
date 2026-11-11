#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
int n;
ll a[MAXN], m;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, ans = 0;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        while (sum > m) sum -= a[i] - a[l++];
        ans = max(ans, i - l + 1);
        if (i != n) sum += 1ll * (i - l + 1) * (a[i + 1] - a[i]);
    }
    cout << ans << '\n';
}