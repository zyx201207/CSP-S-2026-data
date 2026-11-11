#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n, m;
vector<vector<int>> ans;
vector<int> path;
int vis[200005];
void dfs(int s) {
    if (path.size() == m) ans.push_back(path);
    for (int i = s; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        path.push_back(a[i]);
        dfs(i + 1);
        path.pop_back();
        vis[i] = 0;
    }
}
int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    int mx = -1e9;
    for (int i = 0; i < ans.size(); i++) {
        int t = (1 << 31) - 1;
        for (int j = 0; j < ans[i].size(); j++) t &= ans[i][j];
        mx = max(mx, t);
    }
    cout << mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/**
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
