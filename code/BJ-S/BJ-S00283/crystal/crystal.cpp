#include <iostream>
#include <algorithm>

using namespace std;

#define int long long
const int maxn = 5e5 + 10;
int n, m;
int a[maxn], d[maxn];

bool check(int l, int r, int sum) {
    int _ = 0;
    for (int i = l; i <= r; i++) {
        _ += a[r] - a[i];
    }
    cout << l << ' ' << r << ' ' << sum << ' ' << _ << endl;
    return _ != sum;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n - 1; i++) {
        d[i] = a[i + 1] -  a[i];
    }
    int l = 1, r = 1;
    unsigned int sum = 0;

    while (r < n and sum + r * d[r] < m) {
        sum += r * d[r];
        r++;
    }
    int ans = r;
    int bl = 1, br = r;

    while (r < n) {
        sum += (r - l + 1) * d[r];
        r++;
        while (l < r and sum > m) {
            sum -= a[r] - a[l];
            l++;
        }
        if (r - l + 1 > ans) {
            ans = r - l + 1;
            bl = l, br = r;
        }
        //cout << l << ' ' << r << ' ' << ans << endl;
    }

    //cout << bl << ' ' << br << endl;
    cout << ans << endl;
    return 0;
}
