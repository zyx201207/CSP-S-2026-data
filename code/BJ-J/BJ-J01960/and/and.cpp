#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int n, m, p[MAX], sum = 0x3f3f3f3f, maxp, max1, max2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum &= p[i];
        maxp = max(maxp, p[i]);
    }
    if (n == m) {
        cout << (sum == 0x3f3f3f3f ? 0 : sum);
        return 0;
    }
    if (m == 1) {
        cout << maxp;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++) {
            if (j > i) max1 = max(max1, p[i] & p[j]);
            if (j != i) cnt &= p[j];
        }
        max2 = max(max2, cnt);
    }
    if (m == 2) {
        cout << max1;
        return 0;
    }
    if (m == n - 1) {
        cout << max2;
        return 0;
    }
    cout << '\n';
    return 0;
}
