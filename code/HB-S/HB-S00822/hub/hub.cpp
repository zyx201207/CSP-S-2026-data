#include <bits/stdc++.h>
using namespace std;

struct Road {
    int u, v;
} a[1000005];
int c, t, n, kl;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i].u >> a[i].v;

        cout << n / 2;
    }

    return 0;
}
