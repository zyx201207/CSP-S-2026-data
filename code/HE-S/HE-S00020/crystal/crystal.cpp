#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m, cnt;
    cin >> n >> m;
    long long a[n+10] = {0}, b[n+10] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int ii = 1; ii <= n; ii++){
        b[ii] = a[ii];
    }
    for (int j = 1; j <= n; j++){
        for (int k = j; k <= m; k++) {
            b[k]++;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
