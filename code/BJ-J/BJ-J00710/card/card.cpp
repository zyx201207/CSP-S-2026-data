#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cards[500005], pos, ans[500005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pos = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= j - i + 1; k++) {
                if (cards[k] == j) {
                    for (int t = k; t <= j - i + 1; t++) {
                        cards[t] = 0;
                    }
                    pos = k;
                }
            }
            cards[pos + 1] = j;
        }
        for (int j = 1; j <= pos + 1; j++) {
            ans[cards[j]]++;
        }

    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
