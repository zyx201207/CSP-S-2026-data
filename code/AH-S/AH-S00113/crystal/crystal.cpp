#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 100;
int n, ans;
ll m, a[MAXN], s[MAXN];

bool check(int x) {
    for (int i=x; i<=n; i++) {
        ll sum = a[i] * (x - 1) - (s[i - 1] - s[i - x]);
        if (sum <= m) return true;
    }
    return false;
}

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++) cin >> a[i];

    sort(a+1, a+n+1);

    for (int i=1; i<=n; i++) s[i] = s[i-1] + a[i];

    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }

    cout << ans;

    return 0;
}
