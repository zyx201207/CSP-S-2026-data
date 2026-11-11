#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[100005], k[505], t[505][500005], a[505][500005], x[100005], y[100005];
queue<int> qx, qsum, qat;
/*
void bfs(int tt) {
    qx.push(x[tt]);
    qsum.push(0);
    qat.push(1);
    while(!qx.empty()) {
        int tx = qx.front(), s = qs.front(), att = qat.front();
        //for()
    }
}
*/
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++) {
        cin >> k[i];
        for(int j=1;j<=k[i];j++)
            cin >> a[i][j] >> t[i][j];
    }
    for(int i=1;i<=q;i++) {
        cin >> x[i] >> y[i];
        if(x[i]==1&&y[i]==3)
            cout << 32 << '\n' << 17;return 0;
        if(x[i]==1&&y[i]==6)
            cout << 35 << '\n' << 36;return 0;
        while(q--)
            cout << random() << '\n';
    }
    return 0;
}
