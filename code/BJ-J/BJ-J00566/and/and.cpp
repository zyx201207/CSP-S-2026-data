#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
const int FU = 1 << 20;
const int MO = 1 << 25;
int n, m;
int a[N];
int solve (int i) {
    int res = MO, cnt = 1;
    while (i > 0) {
        if (i % 2 == 1) res &= a[cnt];
        cnt ++;
        i >>= 1;
    }
    return res;
}
bool check (int i) {
    int sum = 0;
    while (i > 0) {
        sum += i & 1;
        i >>= 1;
    }
    return sum == m;
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    if (n <= 20) {
        int ans = 0;
        for (int i = 1; i <= FU; i ++) {
            if (check (i) == true) {
                ans = max (ans, solve (i));
            }
        }
        cout << ans;
        return 0;
    }
    if (m == 1) {
        sort (a + 1, a + n + 1);
        cout << a[n];
        return 0;
    }
    if (m == 2) {
        int ans = 0;
        for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) {
            ans = max (ans, a[i] & a[j]);
        }
        cout << ans;
        return 0;
    }
    if (m == n) {
        int ans = a[1];
        for (int i = 2; i <= n; i ++) ans &= a[i];
        cout << ans;
        return 0;
    }
    if (n >= 2000) {
        int ans = 0;
        sort (a + 1, a + n + 1);
        cout << a[n - m + 1];
        return 0;
    }
}
