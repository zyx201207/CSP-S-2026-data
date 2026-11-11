#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2e18

int get(int u, int v, ll d, vector<ll> x) {
    int dist = 0;
    int i = u;
    int last = u;
    while (i < v) {
        while (x[i + 1] - x[last] <= d) i++;
        if (last == i) return 0;
        dist++;
        last = i;
    }
    return dist;
}

int func(int u, int v, ll d, vector<ll> x, int dist) {
    int t = 0;
    if (dist == 0) return 0;
    if (x[v] - x[u] <= d) return 1;
    for (int i = u + 1; i < v && x[i] - x[u] <= d; i++) {
        t += func(i, v, d, x, dist - 1);
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--) {
        
        ll n, d;
        cin >> n >> d;
        vector<ll> x(n);
        for (ll i = 0; i < n; i++) {
            cin >> x[i];
        }
        
        if (c == 11 || c == 12) {
            ll dist = d / (x[1] - x[0]) * 2 - 1;
            if (n > dist && dist != -1) cout << n - dist << '\n';
            else cout << 0 << '\n';
        }

        else {
            int t = 0;
            for (int u = 0; u < n; u++) {
                for (int v = u + 1; v < n; v++) {
                    if (func(u, v, d, x, get(u, v, d, x)) == 2) t++;
                }
            }
            cout << t << '\n';
        }
    }
}