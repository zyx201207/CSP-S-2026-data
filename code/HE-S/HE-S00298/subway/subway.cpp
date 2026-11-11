#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 10;
#define int long long
typedef pair <int ,int> pii;
int c, n, m, d, q, w[N], a[N];
vector <pii> G[N];
void add(int u, int v, int w) {
    G[u].push_back({v, w});
    G[v].push_back({u, w});
}
int cntid = 0;
int f[N][N]; bool vis[N][N];

void diji(int s, int f[N]) {
    f[s] = 0;
    priority_queue <pii, vector <pii>, greater <pii>> q;
    q.push({0, s});
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(vis[s][u]) continue;
        vis[s][u] = 1;
        for(pii _ : G[u]) {
            int v = _.first, w = _.second;
            if(f[u] + w < f[v]) {
                f[v] = f[u] + w;
                q.push({f[v], v});
            }
        }
    }

}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q; cntid = m;



    memset(f, 0x3f, sizeof f);
    for(int i = 1;i <= m;i ++) {
        cin >> w[i];
    }

    for(int _ = 1;_ <= n;_ ++) {
        int k; cin >> k;
        for(int i = 1;i <= k;i ++) {
            int t; cin >> a[i] >> t;
            add(a[i], ++cntid, t);
        }
        ++cntid;
        for(int i = 1;i <= k;i ++) add(cntid - i, cntid, 0);
    }
    for(int i = 1;i <= cntid;i ++) {
        diji(i, f[i]);
    }
    while(q--) {
        int l, r; cin >> l >> r;
        cout << w[l] + w[r] + f[l][r] << endl;
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
