#include <bits/stdc++.h>

using namespace std;

typedef size_t ui;

ui n, m;
ui a[200010];
char c[200010];

int main() {
    freopen("string2.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (ui i = 0; i < n; ++i) {
        cin >> a[i] >> c[i];
        m += a[i];
    }

    ui li = 0, lj = 0, ri = n - 1, rj = a[n - 1] - 1;
    ui ans = 0;
    while (li < ri || li == ri && lj < rj) {
        ui dis = min(
            a[li] + 1 - 1 - lj, 
            rj + 1
        );
        if (c[li] != c[ri]) ans += dis;

        // move l
        lj += dis;
        if (lj >= a[li]) {
            lj -= a[li];
            ++li;
        }

        // move r
        rj -= dis;
        if (rj >= a[ri]) {
            --ri;
            rj += a[ri];
        }
    }

    cout << ans;

    return 0;
}