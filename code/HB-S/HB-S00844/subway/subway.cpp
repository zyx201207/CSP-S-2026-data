#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, M = 5e5 + 10, T = 1e5 + 10;
int n, m, c, d, q, w[M], a, en, k[N][M], state[N][M], t[N][M], maxn = 0x3f3f3f3f;
bool vis[M], dis[M];
void dfs(int time, int st, int end, int x){
    if(time >= maxn) return;
    if(st == end){
        maxn = min(maxn, time);
        return;
    }
    if(k[0][st] <= k[0][end]){
        if( vis[st] ) return;
        vis[st] = true;
        for(int i = 1; i <= k[0][st]; i++){
            for(int j = 1; j <= state[i][0]; j++){
                if(i == x) return;
                if(x && k[i][st] == x) continue;
                dfs(time + t[x][j] + t[k[i][st]][j], state[k[i][st]][j], end, k[i][st]);
            }
        }vis[st] = false;
    }
    else{
        if(dis[end]) return;
        dis[end] = true;
        for(int i = 1; i <= k[0][st]; i++){
            for(int j = 1; j <= state[i][0]; j++){
                if(i == x) return;
                if(x && k[i][st] == x) continue;
                dfs(time + t[x][j] + t[k[i][st]][j], end, state[k[i][st]][j], k[i][st]);
            }
        }vis[st] = false;
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> state[i][0];
            for(int j = 1; j <= 2 * state[i][0]; j++){
                if(j % 2 == 1){
                    cin >> state[i][j];
                    k[0][state[i][j]]++;
                    k[k[0][state[i][j]]][state[i][j]] = i;
                }
                else
                    cin >> t[i][j];
            }
    }
    for(int i = 1; i <= q; i++){
        maxn = 100000000;
        cin >> a >> en;
        dfs(w[a] + w[en], a, en, 0);
        cout << maxn;
    }
    return 0;
}
