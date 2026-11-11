#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
const int N = 1e4 + 10;
int a[N][N], v[maxn], t[N][N];

//A

void solve(){
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i ++){
        int k;
        cin >> k;
        int x1, x2, y1, y2;
        cin >> x1 >> x1 >> y2 >> y2;
        a[x1][y1] = x2;a[y1][x1] = x2;
        t[x1][y1] = y2;t[y1][x1] = y2;
    }
    while(q --){
        int x, y;
        cin >> x >> y;
        cout << v[x] + v[y];
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    solve();
}
