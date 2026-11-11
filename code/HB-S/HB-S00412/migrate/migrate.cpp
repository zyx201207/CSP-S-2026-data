#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c, t, n, d;
ll x[2000006];
bool vis[2000006];

struct node {
    ll i;
    ll step;
};

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;
    while (t--) {
        queue<node> q;
        memset(x, 0, sizeof(x));
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}