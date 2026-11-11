#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[500005];
int ed = 0;
int q[500005];
int pos[300005];
int ans[300005];

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        memset(pos, 0, sizeof(pos));
        memset(q, 0, sizeof(q));
        ed = 0;
        for (int j = i; j <= n; j++) {
            if (pos[a[j]] && q[pos[a[j]]] == a[j] && pos[a[j]] <= ed) ed = pos[a[j]] - 1;
            q[++ed] = a[j];
            pos[a[j]] = ed;
        }
        for (int j = 1; j <= m; j++)
            if (pos[j] && q[pos[j]] == j && pos[j] <= ed) ans[j]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}

