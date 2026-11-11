#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 5e5 + 5;
int a[maxn];
int dis[maxn];
int vis[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dis[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]]) {
            for (int j = vis[a[i]] + 1; j < i; j++) {
				dis[j] -= dis[vis[a[i]]];
				dis[j] = max(0, dis[j]);
			}
        }
        vis[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        vis[a[i]] = max(vis[a[i]], dis[i]);
    }
    for (int i = 1; i <= m; i++)
        cout << vis[i] << " ";
    return 0;
}
