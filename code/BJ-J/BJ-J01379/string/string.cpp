include <bits/stdc++.h>
using namespace

long long n, m, mmax;
long long a[2e9]
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if (n == 0 || m == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                long long d = a[i] + a[j + k];
                mmax = max(mmax, d)
            }
        }
    }
    cout << mmax;
    return 0;
}
