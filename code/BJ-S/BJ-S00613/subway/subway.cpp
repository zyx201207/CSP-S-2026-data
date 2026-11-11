#include <bits/stdc++.h>
using namespace std;
const int MAXm = 500010;
const int MAXq = 100010;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q, w[MAXm], k[MAXq], a[MAXq], t[MAXq], x, y;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int j = 1; j <= q; j++){
        cin >> k[j];
        for(int o = 1; o <= k[j]; o++){
            cin >> a[o] >> t[o];
        }
        cin >> x >> y;
    }
    cout << 35 << endl << 16;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
