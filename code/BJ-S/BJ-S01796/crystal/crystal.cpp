#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans;
void dfs(int z, int idx, long long l, int x) {
    if(idx >= n) {
        if(l >= 0) {
            ans = max(ans, x);
        }
        return;
    }
    dfs(z, idx + 1, l, x);
    dfs(z, idx + 1, l - abs(z - a[idx]), x + 1);
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        dfs(i, 0, m, 0);
    }
    cout << ans << endl;
    return 0;
}