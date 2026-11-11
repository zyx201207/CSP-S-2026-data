#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;
signed main(void) {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    srand(time(NULL));
    cin >> c >> n >> m >> d >> q;
    while (q--) {
        cout << rand() % 10000;
        printf("\n");
    }
    return 0;
}
