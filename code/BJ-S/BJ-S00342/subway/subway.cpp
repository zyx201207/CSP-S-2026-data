#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, p;

long long z[500001];
vector <pair <long long, long long>> g[500001];
long long pre[501][500001];

map <long long, long long> ansn[500001];

void f(long long x, long long root, long long last){
    for (auto t : g[x]){
        long long v = t.first, id = t.second;
        if (ansn[x][v] != 0){
            ansn[x][v] = min(ansn[x][v], pre[id][x] + pre[id][v]);
        }else {
            ansn[x][v] = pre[id][x] + pre[id][v];
        }
        if (ansn[root][v] != 0){
            ansn[root][v] = min(ansn[root][v], last + ansn[x][v]);
        }else {
            ansn[root][v] = last + ansn[x][v];
        }
        f(v, root, ansn[root][v]);
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> p;

    for (int i = 1 ; i <= m ; i++){
        cin >> z[i];
    }

    for (int i = 1 ; i <= n ; i++){
        int k;
        cin >> k;
        if (k == 2){
            long long u1, u2, v1, v2;
            cin >> u1 >> v1 >> u2 >> v2;
            g[u1].push_back({u2, i});
            pre[i][u1] = v1;
            pre[i][u2] = v2;
        }
    }

    for (int i = 1 ; i <= m ; i++){
        f(i, i, 0);
    }

    while (p--){
        long long x, y;
        cin >> x >> y;
        long long ans = z[x] + z[y];
        if (x <= y) cout << ansn[x][y] + ans << endl;
        else cout << ansn[y][x] + ans << endl;
    }

    return 0;
}
