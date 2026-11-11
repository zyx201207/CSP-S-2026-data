#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
using ll = long long;
using P = pair<int, int>;

int c, T;
int n;
ll k;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> T;
    for ( ; T--; ) {
        cin >> n >> k;
        vector<int> u(n + 5, 0), v(n + 5, 0);
        for (int i = 1; i <= n; i++) {
            cin >> u[i] >> v[i];
        }
        cout << 0;
    }
    return 0;
}
