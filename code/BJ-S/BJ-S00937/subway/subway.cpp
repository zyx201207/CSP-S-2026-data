#include <bits/stdc++.h>
using namespace std;
int C, n, m, d, q;
int w[1005], k[505];
int a[505][1005], t[505][1005];
int flag[1005][505];
int g[505][505];

int f[505];
bool inq[505];
void spfa(int st, int en){
    for(int i = 1;i <= n;i++){
        if(flag[st][i] > 0){
            g[0][i] = flag[st][i];
        }
    }
    for(int i = 1;i <= n;i++){
        if(flag[en][i] > 0){
            g[i][n+1] = flag[en][i];
        }
    }
    memset(f, 0x3f, sizeof(f));
    queue<int> q;
    q.push(0);
    inq[0] = 1;
    f[0] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int v = 1;v <= n+1;v++){
            if(g[u][v] > 1000000000) continue;
            if(f[v] > f[u] + g[u][v]){
                f[v] = f[u] + g[u][v];
                if(!inq[v]){
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    cout << f[n + 1] + w[st] + w[en] << endl;;
    for(int i = 1;i <= n;i++){
        if(flag[st][i] > 0){
            g[0][i] = 2e9;
        }
    }
    for(int i = 1;i <= n;i++){
        if(flag[en][i] > 0){
            g[i][n+1] = 2e9;
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> C >> n >> m >> d >> q;
    if(n <= 2){
        int w1[500005];
        for(int i = 1;i <= m;i++)
            cin >> w1[i];
        int fl[500005][3];
        for(int i = 1;i <= n;i++){
            int k;
            cin >> k;
            for(int j = 1;j <= k;j++){
                int x, y;
                cin >> x >> y;
                fl[x][i] = y;
            }
        }
        long long NUM = 1e18;
        for(int i = 1;i <= m;i++){
            if(fl[i][1] > 0 && fl[i][2] > 0){
                NUM = min(NUM, 1ll*fl[i][1] + 1ll*fl[i][2]);
            }
        }
        while(q--){
            int u, v;
            cin >> u >> v;
            long long ans1 = w1[u] + w1[v];
            if(fl[u][1] > 0 && fl[v][1] > 0){
                 ans1 += fl[u][1] + fl[v][1];
            }
            else if(fl[u][2] > 0 && fl[v][2] > 0){
                 ans1 += fl[v][2] + fl[v][2];
            }
            else if(fl[u][1] > 0 && fl[v][2] > 0){
                ans1 += NUM + fl[u][1] + fl[v][2];
            }
            else{
                ans1 += NUM + fl[u][2] + fl[v][1];
            }
            cout << ans1 << endl;
        }
    }
    else {
        for(int i = 1;i <= m;i++){
            cin >> w[i];
        }
        for(int i = 1;i <= n;i++){
            cin >> k[i];
            for(int j = 1;j <= k[i];j++){
                cin >> a[i][j] >> t[i][j];
                flag[a[i][j]][i] = t[i][j];
            }
        }
        memset(g, 0x3f, sizeof(g));
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                for(int k = j + 1;k <= n;k++){
                    if(flag[i][j] > 0 && flag[i][k] > 0){
                        int num1 =(g[j][k], flag[i][k] + flag[i][j]);
                        g[j][k] = g[k][j] = num1;
                    }
                }
            }
        }
        while(q--){
            int s, e;
            cin >> s >> e;
            spfa(s, e);
        }
    }
    return 0;
}