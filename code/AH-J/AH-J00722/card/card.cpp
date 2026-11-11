/*
...Small Cat Go Fishing?
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int n, m, a[N], cnt[N];

int f(int x, int l, int r) {
    for (int i = r; i >= l; i--) if (a[i] == x) return i;
    return -1;
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int rd = 1; rd <= n; rd++) {
        // cerr << rd << ": \n";
        for (int i = rd; i <= n; ) {
            // cerr << i << ' ';
            cnt[a[i]]++;
            i = f(a[i], i, n) + 1;
        }
        // cerr << "\n";
    }
    for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
    return 0;
}
