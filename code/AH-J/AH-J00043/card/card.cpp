#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5010;
const int MAXM = 3010;

int n, m;
int a[MAXN];

int ans[MAXM];

int p[MAXM]; // val -> i
bool added[MAXN];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        memset(p, 0, sizeof(p));
        memset(added, false, sizeof(added));
        for (int j = i; j <= n; j++) {
            if (p[a[j]] != 0) {
                for (int k = p[a[j]]; k < j; k++) {
                    p[a[k]] = 0;
                }
            }
            p[a[j]] = j;
        }

        for (int j = i; j <= n; j++) {
            if (p[a[j]] != 0 && !added[a[j]]) {
                ++ ans[a[j]];
                added[a[j]] = true;
            }
        }
    }

    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
