#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N], b[N];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    if (m == 1) {
        cout << a[1] << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            b[++cnt] = a[i] & a[j];
        }
    }
    sort(b + 1, b + 1 + n, cmp);
    cout << b[1] << endl;
    return 0;
}

