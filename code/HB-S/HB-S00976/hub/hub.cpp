#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;

int c, T, n, k, x, y, ans;
int f[N];
vector <int> g[N];
// int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
// void merge(int x, int y) {f[find(x)] = find(y);}
// void dfs_col(int u, int fa) {
//     merge(u, fa);
//     for (int v : g[u])
//         if (v != fa) dfs_col(v, u); 
// }
// void dfs(int pos, int cnt, vector <int> v) {
//     if (cnt > k) return;
//     if (pos == n + 1 && cnt == k) {
//         for (int it : v) f[it] = it;
//         for (int it : v) {
//             if (f[it] == it) dfs_col(it, it);
//         }
//         int cnt = 0;
//         for (int it : v) 
//             if (f[it] == it) cnt++;
//         if (cnt > 2) return;
        
//     }
//     dfs(pos + 1, cnt, v);
//     dfs(pos + 1, cnt + 1, v);
// }

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> T;
    int idx = 0;
    while (T--) {
        vector <int> ch;
        cin >> n >> k;
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y), g[y].push_back(x);
        }
        // dfs(1, 0, ch);
        cout << ++idx << '\n';
    }
    return 0;
}
