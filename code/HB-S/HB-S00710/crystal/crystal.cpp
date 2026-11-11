#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, a[N], cnt;

long long m;


int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    cin >> a[1] >> a[2];

    int d = a[2] - a[1];
    bool f = 1;

    for (int i = 3; i <= n; i++) {
        cin >> a[i];
        if (a[i] - a[i - 1] != d) f = 0;
    }
    sort (a + 1, a + n + 1);
    int res, pos, rec = m;
    if (f) {
        cnt = 1;
        for (int i = n - 1; i >= 1; i--) {
            if (m >= (a[n] - a[i])) {
                m -= (a[n] - a[i]);
                cnt ++;
            }
            else break;
        }
        cout << cnt << '\n';
    }

    else {
        cnt = INT_MIN;
        for (int num =a[1]; num <= a[n]; num++) {
            res = 0;
            pos = 1;
            m = rec;
            while (pos <= n) {
                if (a[pos] <= num) pos ++;
                else {
                    pos--;
                    break;
                }
            }
            for (int i = pos; i > 0; i--) {
                if (m >= (num - a[i])) {
                    m -= (num - a[i]);
                    res ++;
                }
                else break;
            }
            cnt = max(cnt, res);
        }
        cout << cnt << '\n';
    }
    return 0;
}
