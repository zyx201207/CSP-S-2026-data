#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = -1e18, a[500004];
map<long long, long long> mp;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long sub = a[2] - a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] != sub) {
            flag = true;
        }
    }
    if (!flag) {
        long long sum = 0;
        for (long long i = 1; i <= 500005; i++) {
            sum += i * sub;
            if (i > n) {
                cout << n;
                return 0;
            }
            if (sum > m) {
                cout << i;
                return 0;
            }
        }
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }
    long long prevcnt = 0;
    for (int i = 1; i <= n; i++) {
        long long cur = 0, cnt = 0;
        for (int j = i; j >= 1; j--) {
            cur += a[i] - a[j];
            if (cur > m) {
                break;
            }
            cnt++;
        }
        if (cnt < prevcnt) {
            break;
        }
        prevcnt = cnt;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
