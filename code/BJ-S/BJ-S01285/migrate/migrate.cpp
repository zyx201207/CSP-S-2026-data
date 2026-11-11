#include <bits/stdc++.h>
using namespace std;

int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || '9' < c){
        if(c == '-') f = -1;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
    return f * x;
}

const int N = 5005, INF = 1e9;
int n, d;
int a[N];
pair <int, int> g[N][N];

int dfs(int s, int t){
    if(s == t){
        g[s][t] = {1, 1};
        return 1;
    }
    int cnt = 1, step = INF;
    for(int i = s + 1; i <= t; i++){
        if(a[i] - a[s] > d) break;
        int ge = dfs(i, t) + 1;
        if(ge < step){
            step = ge;
            cnt = 1;
        } else if(ge == step){
            cnt++;
        }
    }
    g[s][t] = {step, cnt};
    return step;
}

void work(){
    memset(g, 0, sizeof(g));
    memset(a, 0, sizeof(a));
    n = read(), d = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            dfs(i, j);
            if(g[i][j].second == 2){
                ans++;
                // cout << i << " -> " << j << '\n';
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c = read(), t = read();
    while(t--){
        work();
    }
    return 0;
}