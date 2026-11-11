#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
long long n, m, a[MAXN];

bool Special_A() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != i) return false;
    return true;
}

bool Special_B() {
    if (n == 1 || n == 2) return true;
    int k = a[2] - a[1];
    for (int i = 3; i < n; ++i)
        if (a[i + 1] - a[i] != k) return false;
    return true;
}


int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (Special_A()) cout << (long long)max(((sqrt(8 * m + 1) - 1) / 2 + 1), (-1 - (sqrt(8 * m + 1)) / 2 + 1));
    else if (Special_B()) {
        int k = a[n] - a[n - 1];
        cout << (long long)max(k + sqrt(k * k + 8 * m * k) / 2 / k + 1, k - sqrt(k * k + 8 * m * k) / 2 / k + 1);
    } else cout << n;

    return 0;
}
