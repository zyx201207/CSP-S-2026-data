#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], t[300005], vis[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        deque<int> q;
        q.push_back(a[i]);
        memset(vis, 0, sizeof(vis));
        vis[a[i]] = 1;
        for(int j = i + 1; j <= n; j++) {
            if(vis[a[j]]) {
                while(!q.empty() && q.back() != a[j]) {
                    vis[q.back()] = 0;
                    q.pop_back();
                }
                q.pop_back();
                vis[a[j]] = 0;
            }
            q.push_back(a[j]);
            vis[a[j]] = 1;
        }
        while(!q.empty()) {
            t[q.front()]++;
            q.pop_front();
        }
    }
    for(int i = 1; i <= m; i++) cout << t[i] << " ";
    return 0;
}
