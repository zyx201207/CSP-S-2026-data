#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5, M = 3 * 1e5 + 5;
int n, m;
int a[N], ans[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int t = 1; t <= n; ++t) {
        int q[M] = {0};
        int idx = 0;
        int book[M] = {0};
        for (int i = t; i <= n; ++i) {
            int k = a[i];
            if (!book[k]) {
                book[k] = 1;
                q[++idx] = k;
            } else {
                int where;
                for (int j = 1; j <= i; ++j) {
                    if (q[j] == k) {
                        where = j;
                        break;
                    }
                }
                for (int j = where; j <= i; ++j) {
                    q[j] = 0;
                }
                idx = where;
                q[idx] = k;
            }
        }
        for (int i = 1; i <= idx; ++i) {
            ans[q[i]]++;
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
