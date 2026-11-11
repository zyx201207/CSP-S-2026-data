#include <bits/stdc++.h>

using namespace std;

int c, t, n, k, minn = 0x3f3f3f3f;
int dist[1010];
vector<int> a[1010];

int dfs(int x, int y, int depth){
    int ans = 0;
    if(x == y) return depth;
    if(a[x].empty()) return 0;


    for(auto u : a[x])  ans += dfs(u, y, depth + 1);

    return ans;
}

int f(int i, int j, int k){
    int ans1 = dfs(i, k, 0), ans2 = dfs(j, k, 0);
    return min(ans1, ans2);
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;

    if(c == 7 || c == 11 || c == 12){
        while(t--){
            cin >> n >> k;

            for(int i = 1; i < n; i++){
                int u, v;
                cin >> u >> v;
                a[u].push_back(v), a[v].push_back(u);
            }

            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    int maxn = 0;
                    for(int k = 1; k <= n; k++){
                        if(k == i || k == j) dist[k] = 0;
                        else dist[k] = f(i, j, k);
                        maxn = max(maxn, dist[k]);
                    }

                    minn = min(minn, maxn);
                }
            }

            cout << minn << endl;
        }
    }

    return 0;
}
