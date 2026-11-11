/*
地铁双向任意通行
*/

#include <iostream>
#include <vector>
using namespace std;
int c, n, m, d, q, w[500001], k[500001], a;
vector <int> g[500001];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a;
            
        }
    }
    return 0;
}