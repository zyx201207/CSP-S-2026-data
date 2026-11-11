#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, k;
long long w[500010], a[510][500010], t[510][500010], r[100010][2], b[500010];

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=0; i<n; i++) {
        cin >> k;
        for(int j=0; j<k; j++) {
            int x, y;
            cin >> x >> y;
            a[i][x]++, t[i][x]=y;
            if(b[x]) b[x] = min(b[x], y);
            else b[x] = y;
        }
    }
    for(int i=0; i<q; i++) {
        int r1, r2;
        cin >> r1 >> r2;
        cout << w[r1] + w[r2] + b[r1] + b[r2] << endl;
    }

    return 0;
}
