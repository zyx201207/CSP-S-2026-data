#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500001] ,k[501];
int a[501][500001], t[501][500001];

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1; i <= m; ++i) {
        cin >> w[i];
    }

    for(int i = 1; i <= n; ++i) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; ++j) {
            cin >> a[i][j] >> t[i][j];
        }
    }

    while(q--) {
        int st, ed;
        cin >> st >> ed;

        cout << w[st] + t[st][st] + t[st][ed] + w[ed] << '\n';
    }

    return 0;
}
