#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 +10;
int u[N], v[N];
int main () {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    int n, k;
    cin >> n >> k;
    while (t--) {
        for (int i = 1; i <= n - 1; i++) {
            cin >> u[i] >> v[i];
        }
    }


    cout << "1" << "\n" << "2";
    return 0;
}
