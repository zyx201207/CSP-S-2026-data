#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 1e6 + 10, maxn2 = 10 + 10;

struct{
    int v, nex;
} edge[maxn << 1];

int c, t, n, k, res;
int dis[maxn2][maxn2], fat[maxn];
int head[maxn], top;

inline void add(int u, int v, bool o = true){
    edge[++top].v = v, edge[top].nex = head[u], head[u] = top, o && (add(v, u, false), 1538);
}

inline void dfs(int u, int fa, int* dis){
    fat[u] = fa;
    for (int i = head[u]; i; i = edge[i].nex){
        const int v = edge[i].v;
        v != fa && (dis[v] = dis[u] + 1, dfs(v, u, dis), 1538);
    }
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while (t--){
        scanf("%d %d", &n, &k), res = 1e9, top = 0;
        for (int i = 1; i <= n; head[i++] = 0);
        for (int i = 1; i < n; i++){
            int u, v;
            scanf("%d %d", &u, &v), add(u, v);
        }
        if (c <= 3){
            for (int i = 1; i <= n; i++){
                dfs(i, 0, dis[i]);
            }
            for (int sta = 0; sta < 1 << n; sta++){
                int cnt = 0, cnt2 = 0;
                for (int i = 1; i <= n; i++){
                    cnt += sta >> i - 1 & 1;
                    if (sta >> i - 1 & 1){
                        cnt2 += !fat[i] || !(sta >> fat[i] - 1 & 1);
                    }
                }
                int now = 0;
                for (int i = 1; i <= n; i++){
                    int mn = 1e9;
                    for (int j = 1; j <= n; j++){
                        sta >> j - 1 & 1 && (mn = min(mn, dis[j][i]));
                    }
                    now = max(now, mn);
                }
                cnt == k && cnt2 <= 2 && (res = min(res, now));
            }
            printf("%d\n", res);
        }else if (c == 13 || c == 14){
            const int m = (n + 1 >> 1) + 1;
            printf("%d\n", max(0, (m - k + 3) >> 2));
        }
    }

return 0;
}