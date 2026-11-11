#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long dp[500005], b[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

    }
    sort(a, a + n);
    // hack
    int dengcha = true, _d = a[1] - a[0];
    for (int i = 1; i + 1 < n; i++) {
        if (_d != a[i+1] - a[i]) {
            dengcha = false;
            break;
        }
    }
    if (dengcha) {
        int d = _d;
        int num = 0;
        while(num * (num+1) * d < m * 2) num++;
        num--;
        //cout << num+1;
        return 0;
    }
    int res = 0x8FFF0000, ans = 1;
    int j = 0;
    for (int i = 1; i <= n; i++, ans++) {
    int try_add = 0;

        for (int j = 0 ; j < i; j++) {
            try_add += a[i] - a[j];
    //cout << ":" << try_add << "; " << a[i] << "-" << a[j] << endl;
        }
        ///cout << "::" << ans << endl;
        //cout << endl;
        if (try_add > m) break;
        if (try_add > res) {
            res = try_add;
        }
    }
    cout << ans;
    return 0;
}














































































































