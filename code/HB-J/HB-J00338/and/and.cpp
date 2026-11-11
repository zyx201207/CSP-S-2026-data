#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
bool a[200005][35], bad[200005];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; x > 0; j++)
            a[i][j] = x % 2, x /= 2;
    }
    for (int i = 29; i >= 0; i--) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += (!bad[j] & a[j][i]);
        if (sum >= m) {
            ans += pow(2, i);
            for (int j = 0; j < n; j++)
                bad[j] |= !a[j][i];
        }
    }
    cout << ans;
    return 0;
}
