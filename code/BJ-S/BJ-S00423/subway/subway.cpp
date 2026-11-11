#include<bits/stdc++.h>
using namespace std;
const int N = 20000;
int a[N][N], c, n, m, d, q, b[N], k;
void fun(){
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 1; k <= m; k++){
                a[i][j] = a[j][i] = min(a[i][j], a[i][k] + a[k][j]);
            }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    memset(a, 0x3f, N);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> b[N];
    for(int i = 1; i <= n; i++){
        int x1, y1, x2, y2;
        cin >> k >> x1 >> y1 >> x2 >> y2;
        a[x1][x2] = a[x2][x1] = y1 + y2;
    }
    fun();
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >>y;
        cout << a[x][y] + b[x] + b[y] << endl;
    }
    return 0;
}
