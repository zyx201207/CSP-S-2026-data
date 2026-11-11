#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], pos[300005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        cout << pos[i] + 1 << " ";
    }
    return 0;
}
