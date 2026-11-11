#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, m, num[N], a[N], sum[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    if (m == 1) {
        cout << n;
        return 0;
    }
    else {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            num[a[i]] ++;
        }
        for (int i = 1; i <= m; i++) {
            sum[i] = sum[i - 1] + num[i];
            cout << sum[i] << ' ';
        }
    }
    return 0;
}
