#include<bits/stdc++.h>

using namespace std;

bool cmp(int i, int j) {
    return i > j;
}

int n, m, a[200005];
int ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    ans = a[1];
    for(int i = 1; i <= m; i++) {
        ans = ans & a[i];
    }
    cout << ans;
    return 0;
}
