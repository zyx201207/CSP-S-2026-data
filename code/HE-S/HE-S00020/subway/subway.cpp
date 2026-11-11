#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    long long c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    long long cc[c + 10], nn[n + 10], mm[m + 10], dd[d + 10], qq[q + 10];
    for (int ccc = 1; ccc <= c; ccc++){
        cin >> cc[ccc];
    }
    for (int nnn = 1; nnn <= n; nnn++){
        cin >> nn[nnn];
    }
    for (int mmm = 1; mmm <= m; mmm++){
        cin >> mm[mmm];
    }
    for (int ddd = 1; ddd <= d; ddd++){
        cin >> dd[ddd];
    }
    for (int qqq = 1; qqq <= q; qqq++){
        cin >> qq[qqq];
    }



    for (int i = 1; i <= c; i++){
        cout << cc[i];
    }
    for (int i = 1; i <= n; i++){
        cout << nn[i];
    }
    for (int i = 1; i <= m; i++){
        cout << mm[i];
    }
    for (int i = 1; i <= d; i++){
        cout << dd[i];
    }
    for (int i = 1; i <= q; i++){
        cout << qq[i];
    }
    return 0;
}
