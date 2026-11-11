#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long a[N], f[N], q[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (n <= 500) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                long long x = 0;
                // if (i == 5 && j == 8) cout << "/";
                for (int k = i; k <= j - 1; k++) {
                    x += a[j] - a[k];
                }
                if (x <= m) {
                    // if (j - i + 1 > ans) {
                    //     cout << i << " " << j << "\n";
                    // }
                    ans = max(ans, j - i + 1);
                }
            }
        }
        cout << ans << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = a[i] - a[i - 1];
    }
    long long anss = 1;
    long long ans = 1;
    long long sum = 0;
    int l = 1;
    for (int i = 2; i <= n; i++) {
        long long sum1 = f[i];
        sum += (i - l) * sum1;
        if (sum <= m) {
            ans++;
        } else {
            long long c = sum - m;
            c = (c + sum1 - 1) / sum1;
            l += c;
            ans -= c - 1;
            sum -= c * sum1;
        }
        anss = max(ans, anss);
    }
    cout << anss;
    return 0;
}
/*
5 2
1 8 10 10 10
*/