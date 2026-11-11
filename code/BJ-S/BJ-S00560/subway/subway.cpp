#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    static int sgn, res; sgn = 0, res = 0; static char ch = getchar();
    while(!isdigit(ch)) sgn ^= (ch == '-'), ch = getchar();
    while(isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
    return sgn ? -res : res;
}

const int N = 5e5 + 10;
int c, n, m, d, q, ans, T;
vector<int> g[N];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; i++)
        T = read();
    for(int i = 1; i <= n; i++){
        int k;
        k = read();
        for(int j = 1; j <= k; j++){
            int v, T;
            v = read(), T = read();
            g[i].push_back(v);
        }
    }
    while(q--){
        int x, y;
        x = read(), y = read();
        queue<int> q;
        int dis[N], inq[N];
        fill(dis + 1, dis + 1 + m, 1e18);
        memset(inq, 0, sizeof(inq));
        q.push(x);
        dis[x] = 0;
        inq[x] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for(auto v : g[u]){
                if(dis[v] > dis[u] + 4 * T){
                    dis[v] = dis[u] + T;
                    if(!inq[v])
                        q.push(v);
                }
            }
        }
        cout << dis[y] << endl;
    }
    return 0;
}