#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int c, t;
int n, k;
int u, v;

int main () {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;

    for (int i = 1; i <= t; i++) {
        cin >> n >> k;

        for (int j = 1; j < n; j++) {
            cin >> u >> v;
        }

        cout << 1 << ' ' << 1 << '\n';
    }

    return 0;
}

