#include <bits/stdc++.h>
using namespace std;
int n, m, d[200005], ans;
void dfs(int a, int b, int c){
    if (n - a + 1 + b < m) return;
    if (b == m){
        ans = max(ans, c);
        return;
    }
    dfs(a + 1, b + 1, c & d[a]);
    dfs(a + 1, b, c);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    dfs(1, 0, INT_MAX);
    cout << ans;
    return 0;
}
