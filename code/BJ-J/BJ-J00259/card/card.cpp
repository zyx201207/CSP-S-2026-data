#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005], ans[300005];
int nxt[300005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        nxt[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int pos = i;

        while (pos <= n) {
            ans[a[pos]]++;
            
            pos = nxt[a[pos]] + 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}