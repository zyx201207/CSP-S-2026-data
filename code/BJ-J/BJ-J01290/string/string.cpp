#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    vector<int>a(n + 1);
    vector<char>c(n + 1);
    long long m = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        m += a[i];
    }
    long long ans = 0;
    long long x = 0, y = 0;
    char x1, x2;
    int i = 1, j = n;
    int d = n / 2;
    int e = (n % 2 == 0 ? n / 2 + 1 : n / 2 + 1);
    while (i <= d && j >= e) {
        if (x == 0) {
            x += a[i];
            x1 = c[i];
        }
        if (y == 0) {
            y += a[j];
            x2 = c[j];
        }
        if (x1 != x2) {
            ans += min(x, y);
        }
        if (x > y) {
            x -= y;
            y = 0;
        }
        else {
            y -= x;
            x = 0;
        }
        if (x == 0) {
            i++;
        }
        if (y == 0) {
            j--;
        }
    }
    ans += min(x, y);
    cout << ans;
    return 0;
}
