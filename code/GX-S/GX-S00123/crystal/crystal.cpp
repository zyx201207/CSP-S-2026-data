#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 5e5 + 1;
int n, ans;
ll m, a[N];
int check(int i) {
    ll now = 0;
    int cnt = 0;
    for (int j = 1; j < i; j++) {
        if (now + a[i] - a[j] <= m) {
            now += a[i] - a[j];
            cnt++;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2, res = check(mid);
        if (res >= ans) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
