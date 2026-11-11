#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N];
void m1() {
    int x;cin >> x;
    cout << x;
}
void mn() {
    int sum;cin >> sum;
    for (int i = 1; i < n; i ++) {
        int x;cin >> x;
        sum = sum & x;
    }
    cout << sum;
}
void m2() {
    int sum1 = 0, sum2 = 0, ai;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] >= sum1) {
            ai = i;
            sum1 = a[i];
        }
    }
    a[ai] = -1;
    for (int i = 1; i <= n; i ++) {
        sum2 = max(sum2, a[i]);
    }
    cout << (sum1 & sum2);
}
bool cmp(int x, int y) {return x > y;}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if (m == 1) m1();
    else if (m == n) mn();
    else if (m == 2) m2();
    else {
        for (int i = 1; i <= n; i ++) cin >> a[i];
        sort(a + 1, a + n + 1, cmp);
        int sum = a[1];
        for (int i = 2; i <= m; i ++) sum = sum & a[i];
        cout << sum;
    }
    return 0;
}