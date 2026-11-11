#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int NR = 2e6 + 10;
vector<int> G[NR];
bool fl[NR];
bool vis[NR];

void dfs(int u, int fa) {
    //printf("dfs %d\n", u);
    vis[u] = true;
    for(int v : G[u]) {
        if(v == fa || !fl[v]) continue;
        dfs(v, u);
    }
}

int ans;

int fdis(int u, int fa) {
    if(fl[u]) return 0;
    int res = 1e9;
    for(int v : G[u]) {
        if(v == fa) continue;
        res = min(res, fdis(v, u) + 1);
    }
    return res;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T;
    scanf("%d%d", &c, &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(c <= 3) {
            ans = 1e9;
            for(int S = 1; S < (1 << n); S++) {
                int num = 0;
                for(int i = 1; i <= n; i++) {
                    if((S >> i - 1) & 1) {
                        fl[i] = true;
                        num++;
                    }
                    else fl[i] = false;
                    vis[i] = false;
                }
                if(num > k) continue;
                int cnt = 0;
                for(int i = 1; i <= n; i++) {
                    if(fl[i] && !vis[i]) {
                        if(++cnt > 2) break;
                        //printf("  to_dfs %d\n", i);
                        dfs(i, 0);
                    }
                }
                if(cnt > 2) continue;
                int mx = 0;
                for(int i = 1; i <= n; i++) {
                    mx = max(mx, fdis(i, 0));
                }

                /*
                if(mx < ans) {
                    printf("=======ans=%d\n", mx);
                    for(int i = 1; i <= n; i++) {
                        if(S >> i - 1 & 1) {
                            printf("%d ", i);
                        }
                    }
                    puts("");
                }
                */

                ans = min(ans, mx);
            }
            printf("%d\n", ans);
        }
        // clear
        for(int i = 1; i <= n; i++) G[i].resize(0);
    }
    return 0;
}

