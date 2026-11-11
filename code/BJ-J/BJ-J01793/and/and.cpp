#include <bits/stdc++.h>

using namespace std;

typedef size_t ui;

ui n, m;
ui a[200010];
bool is[200010];

ui cnum(ui e) {
    ui res = 0;
    for (int i = 0; i < n; ++i) {
        if (!is[i]) continue;
        res += (a[i] >> e) & 1;
    }
    return res;
}

ui cpt() {
    ui res = -1;
    for (int i = 0; i < n; ++i) {
        if (!is[i]) continue;
        res &= a[i];
    }
    return res;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (ui i = 0; i < n; ++i)
        cin >> a[i], is[i] = 1;


    ui exp = -1;
    for (ui e = 29; ~e; --e) {
        ui num = cnum(e);
        if (num >= m) {
            for (int i = 0; i < n; ++i) {
                bool bit = (a[i] >> e) & 1;
                if (!bit) is[i] = 0;
            }
        }
        if (num == m) {
            cout << cpt();
            return 0;
        }
        if (num < m) {
            // pass
        }
    }

    cout << cpt();
    return 0;
}