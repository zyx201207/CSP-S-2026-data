#include<bits/stdc++.h>
using namespace std;
int n, d;
long long x[2000005];
int sum = 1e9;
map<int, int> g;
void dfs(int idx, int e, int len) {
    if(idx == e) {
        sum = min(sum, len); 
        g[len]++;
    }
    if(len > sum) return;
    if(idx > e) return;
    for(int i = idx + 1; i <= n; i++) {
        if(x[i] - x[idx] > d) break;
        dfs(i, e, len + 1);
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                dfs(i, j, 0);
                if(g[sum] == 2) ans++;
                sum = 1e9;
                g.clear();
            }
        }
        cout << ans << endl;
    }
    return 0;
}
