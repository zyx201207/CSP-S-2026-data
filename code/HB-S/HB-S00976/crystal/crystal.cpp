#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;

int n;
ll m, a[N], s[N];
bool check(int id) { // the number of crystal is x
    int idx = id - 1;
    for (int i = id; i <= n; i++) { // want to get x your num at least need x
        int l = i - idx, r = i - 1;
        ll sum = s[r] - s[l - 1];
        if (a[i] * 1ll * idx - sum <= m) return 1;
    }
    return 0;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1; 
    }
    cout << ans << '\n';
    return 0;
}