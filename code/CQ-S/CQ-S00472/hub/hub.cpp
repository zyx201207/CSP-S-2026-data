#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define endl '\n'
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]) {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int cse{}, times{};
    cin >> cse >> times;
    while (times--) {
        int n{}, k{};
        cin >> n >> k;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i++) {
            int u{}, v{};
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> fa(n + 1, -1);
        vector<int> dep(n + 1, 0); dep[1] = 0;
        stack<int> stk{}; stk.push(1);
        vector<bool> vis(n + 1, false); vis[1] = true;
        while (!stk.empty()) {
            int u = stk.top(); stk.pop();
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                if (!vis[v]) {
                    vis[v] = true;
                    fa[v] = u;
                    dep[v] = dep[u] + 1;
                    stk.push(v);
                }
            }
        }
        int ans = 0;
        for (int u = 1; u <= n; u++)
        for (int v = u + 1; v <= n; v++) {
            int i = u, j = v;
            if (dep[i] < dep[j]) {
                swap(i, j);
            }
            for (int d = 0; d < dep[i] - dep[j]; d++) {
                i = fa[i];
            }
            while (i != j) {
                i = fa[i], j = fa[j];
            }
            ans = max(ans, dep[u] - dep[i] + dep[v] - dep[i]);
        }
        cout << ans << endl;
    }
    return 0;
}