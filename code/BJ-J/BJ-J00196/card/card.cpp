#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll a[N], ans[N], n, m, pos[N];
bool check() {
    for (ll i = 1; i <= n - 1; i++) if (a[i + 1] < a[i]) return 0;
    return 1;
}
void Print() {
    for (ll i = 1; i <= m; i++) cout << ans[i] << " ";
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = max(pos[a[i]], i);
    }
    if (check()) {
        for (ll i = 1; i <= m; i++) ans[i] = pos[i];
        Print();
    } else {
        for (ll i = 1; i <= n; i++) {
            ll j = i;
            set <ll> res;
            res.insert(a[j]);
            while (j <= n) {
                if (pos[a[j]] != j) j = pos[a[j]];
                else {
                    res.insert(a[j + 1]);
                    j++;
                }
            }
            for (const auto &it : res) ans[it]++;
        }
        Print();
    }
    return 0;
}
