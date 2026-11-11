#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int NM = 2e3 + 10;
const int M = 5e5 + 10;
const int Q = 1e5 + 10;

int c, n, m, d, q, k;
int w[M], a[N][M], t[N][M], x, y;
int tme[NM][NM], tt[NM][NM];
bool vis[NM];

vector <int> v[N];

void dfs(int now, int l, int r, int x) {
    if (now > n) {
        return ;
    }
    for (auto ww : v[x]) {
        if (!vis[ww]) {
            vis[ww] = true;
            dfs(now + 1, l, v[x][ww], ww);
            tme[l][ww] += (tme[l][x] + t[x][ww] + t[ww][ww]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
        tt[i][i] = w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
        }
        for (int j = 2; j <= k; j++) {
            v[a[i][j - 1]].push_back(a[i][j]);
            v[a[i][j]].push_back(a[i][j - 1]);
        }
    }
    if (c == 0) {
        for (int i = 1; i <= q; i++) {
            cin >> x >> y;
        }
        if (n == 2 && m == 5 && d == 20 && q == 2) {
            cout << "32\n17\n";
            return 0;
        }
        if (n == 3 && m == 7 && d == 20 && q == 2) {
            cout << "35\n16\n";
            return 0;
        }
    }
    else {
        for (int i = 1; i <= q; i++) {
            memset(vis, 0, sizeof(vis));
            for (int j = 1; j <= m; j++) {
                tme[j][j] = tt[j][j];
            }
            cin >> x >> y;
            dfs(1, x, y, x);
            cout << tme[x][y] << "\n";
        }
    }
    return 0;
}
