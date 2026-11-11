#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int c, n, m, d, q;
ll w[N], a[N], cnt[N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    int l = 1, r;
    for (int i = 1; i <= n; i++) {
        int cx;
        cin >> cx;
        r = i * 2 * cx;
        for (int i = l; i <= r; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        l = 2 * cx + i;
    }
    while (q--) {
        int ans = 0, x, y;
        cin >> x >> y;
        int sum = x;
        for (int i = 1; i <= r; i++) {
            if (cnt[x] > 1) {
                for (int j = 1; j <= r; j++) {
                    if (j == x) {
                        sum = j;
                        if (a[i + 2] == y) {
                            sum = j;
                        }
                    }
                }
            }
        }
        for (int i = sum; i <= r; i++) {
            if (a[i] == x) {
                if (a[i + 2] == y) {
                    for (int j = 1; j <= r; j++) {
                        if (j == x) {
                            sum = j;
                            if (a[i + 2] == y) {
                                sum = j;
                                break;
                            }
                        }
                    }
                    x = sum;
                    ans += a[i + 1] + a[i + 3] + w[a[i + 2]] + w[sum];
                } else if (cnt[x] == 1) {
                    int minn = N;
                    for (int j = 1; j <= r; j++) {
                        if (j == x) {
                            if (a[i + 2] == y) {
                                sum = j;
                                break;
                            } else {
                                if (a[sum + 1] < minn) {
                                    minn = a[sum + 1];
                                    sum = j;
                                } else if (a[sum + 1] > minn) {
                                    continue;
                                }
                            }
                        }
                    }
                    x = sum;
                    ans += a[sum + 1] + a[sum + 3] + w[a[sum + 2]] + w[sum];
                    for (int j = 1; j <= r; j++) {
                        if (j == a[sum + 2]) {
                            if (a[j + 2] == a[sum + 2]) {
                                sum = j;
                                break;
                            }
                        }
                    }
                } else {
                    for (int j = 1; j <= r; j++) {
                        if (j == x) {
                            sum = j;
                            if (a[i + 2] == y) {
                                sum = j;
                                break;
                            }
                        }
                    }
                    x = sum;
                    ans += a[i + 1] + a[i + 3] + w[a[i + 2]] + w[sum];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
