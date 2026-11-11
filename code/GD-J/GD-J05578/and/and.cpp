#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;
int a[N];

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cout << a[n - m + 1] << endl;
    return 0;
}
