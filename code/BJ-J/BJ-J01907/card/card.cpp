#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500005;
const int INF = 300005;
int n, m;
int a[MAX_N];
int ans[INF];
stack <int> table;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for (int tim = 1; tim <= n; tim++) {
        int vis[INF];
        for (int i=1; i<=m; i++) {
            vis[i] = 0;
        }

        for (int i = tim; i<=n; i++) {
            if (vis[a[i]] == 1) {
                while (!table.empty()) {
                    int first = table.top();
                    table.pop();
                    if (first == a[i]) break;
                    else vis[first] = 0;
                }
            }
            table.push(a[i]);
            vis[a[i]] = 1;
        }

        for (int i=1; i<=m; i++) {
            ans[i] += vis[i];
        }

    }

    for (int i=1; i<=m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
