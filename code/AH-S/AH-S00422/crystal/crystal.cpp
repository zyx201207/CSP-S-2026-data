#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 5e5 + 10;
int n, ans;
ll m, a[N];

bool check(int mid) {
    ll t;
    for (int i = mid; i <= n; i++) {
        t = 0LL;
        for (int j = i - mid + 1; j < i; j++) t += a[i] - a[j];
        if (t <= m) return true;
    }
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int l = 1, r = n, mid; l <= r; ) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
