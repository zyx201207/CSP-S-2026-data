#include <bits/stdc++.h>

using namespace std;

typedef size_t ui;

ui n, m;
ui a[500010];
ui ans[300010];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        ui desk[500010] {};
        ui n_desk = 0;
        for (int k = i; k <= n; ++k) {
            int idx_k = -1;
            for (int j = 0; j < n_desk; ++j) {
                if (desk[j] == a[k]) {
                    idx_k = j;
                    break;
                }
            }
            if (idx_k == -1) {
                desk[n_desk++] = a[k];
            } else {
                n_desk = idx_k + 1;
            }
        }
        
        for (int j = 0; j < n_desk; ++j) {
            ans[desk[j]]++;
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}