#include <iostream>
#include <queue>
using namespace std;
const int N = 5E5 + 5;
int a[N], h[N], pos[N], ans[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) h[j] = pos[j] = 0;
        for (int j = i; j <= n; j++) {
            if (h[a[j]])
                for (int k = pos[a[j]]; k <= j; k++)
                    h[a[k]] = pos[a[k]] = 0;
            h[a[j]] = 1;
            pos[a[j]] = j;
        }
        for (int j = 1; j <= m; j++)
            if (h[j]) ans[j]++;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i];
        if (i != m) cout << ' ';
    }
    return 0;
}
