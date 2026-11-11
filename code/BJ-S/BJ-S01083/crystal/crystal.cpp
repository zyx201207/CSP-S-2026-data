#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 * 5 + 5;
long long n, m;
long long a[N], maxx;
long long cnt, ans;
bool x = 1;

int main () {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        if (a[i] != i) {
            x = 0;
        }
    }

    if (x == 1) {
        int y = 0, z = 0;
        while (1) {
            z++;
            y += z;
            if (y > m) {
                cout << z;
                return 0;
            }
        }
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= maxx; i++) {
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] > i) {
                break;
            }
            if (m >= i - a[j]) {
                m = m - i + a[j];
                cnt++;
            } else if (m  >= a[j-1] - a[j]) {
                m  = m - a[j-1] + a[j];
            }
        }
        ans = max(cnt, ans);
    }

    cout << ans;

    return 0;
}
