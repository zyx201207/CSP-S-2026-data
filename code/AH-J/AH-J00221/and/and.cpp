#include<bits/stdc++.h>

using namespace std;

int n, m;
int ans = -1;
int a[200005];

inline void dfs(int i, int x, int last) {
    if (i == m + 1) {
        ans = max(ans, x);
        return;
    }
    for (int j = 1; n - j >= i; j++)
        dfs(i + 1, x & a[last + j], last + j);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 1073741823, 0);
    cout << ans;
    return 0;
}
