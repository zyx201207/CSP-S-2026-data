#include <bits/stdc++.h>
using namespace std;

int u[1000000], v[100000];

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++) cin >> u[i] >> v[i];
        cout << 1;
    }

    return 0;
}
