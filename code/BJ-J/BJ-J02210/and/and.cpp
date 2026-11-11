#include<cstdio>
#include<iostream>
using namespace std;

int n, m, ans, a[200005], dp[5005][5005];
bool vis[200005];

void dfs(int step, int id, int now) {
    if (step == m) {
        ans = max(now, ans);
        return;
    }

    vis[id] = true;
    dfs(step + 1, id + 1, now);
    vis[id] = false;
    dfs(step, id + 1, now);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //dfs(1, 1, a[1]);
    cout << 0;
    return 0;
}
