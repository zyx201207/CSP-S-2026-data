#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int n, m, ans = 0;
int check(int x) {
    int sum = 0, num = 0;
    for (int i = x; i >= 1; i --) {
        if (num + a[x] - a[i] > m) break;
        num += a[x] - a[i], sum ++;
    }
    return sum;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i --) {
        ans = max(ans, check(i));
    }
    cout << ans;
    return 0;
}
