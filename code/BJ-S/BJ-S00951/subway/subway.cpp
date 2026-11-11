#include <bits/stdc++.h>
using namespace std;
#define ll long long

int w[500005], C, c, n, m, d, q, x[500005], y[500005], lj[500005][500005];// ll ans;
bool ch[500005];

ll BFS(int st, int en, int li, ll sum, int xl) {
    if (st == en) return sum;
    // if (sum >= ans) return sum;
    for (int i = 0; i < m;++i) {
        if(lj[st][i] != 0 && i != li) {
            for (int j = 0; j < n; j++) {
                if (lj[j][x[i]] != 0 && j != xl)
                    return BFS(i, en, st, sum, j) + lj[j][x[i]];
                else if (lj[j][x[i]] != 0 && j == xl)
                    return BFS(i, en, st, sum, j);
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q; C = c;
    for (int i =0; i<m; ++i) {
        cin >> w[i];
    } for (int i =0; i<n; ++i) {
        int k; cin >> k;
        for (int j =0; j<k; ++j) {
            ll tmp, temp;
            cin >> tmp >> temp;
            lj[i][tmp] = temp;
        }
    } for (int i = 0; i < q; i++) {
            cin >> x[i] >> y[i];
    } for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++)
            if (lj[j][x[i]] != 0) cout << w[x[i]] + BFS(x[i], y[i], -1, 0, j) + w[y[i]];
    } return 0;
}
