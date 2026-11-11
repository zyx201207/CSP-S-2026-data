#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> card;
int a[500010], tong[500010], f[500010];

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        card.clear();
        memset(f, -1, sizeof f);
        for (int j = i; j <= n; ++j) {
            if (f[a[j]] != -1) {
                int sz = card.size() - 1;
                while (sz > f[a[j]]) {
                    tong[card.back()]--;
                    f[card.back()] = -1;
                    card.pop_back();
                    sz--;
                }
            } else {
                card.push_back(a[j]);
                f[a[j]] = card.size() - 1;
                tong[a[j]]++;
            }
        }
    }
    for (int i = 1; i <= m; ++i) cout << tong[i] << ' ';
    cout << '\n';
    return 0;
}
