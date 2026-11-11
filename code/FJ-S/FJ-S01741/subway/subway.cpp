#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
    int x = 0, ff = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') c = getchar(), ff = -1;
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * ff;
}
const int N = 510, M = 1.1e6;
const LL inf = 1e18;
int n, m, D, Q;
LL a[M];
int head[M], to[M * 2], nxt[M * 2], tot;
LL w[M * 2], dist[N][N];
void add_edge(int x, int y, int z){
    ++tot;
    to[tot] = y;
    nxt[tot] = head[x];
    w[tot] = z;
    head[x] = tot;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int casecnt = 1, caseidd = read();
    while(casecnt --){
        n = read(), m = read(), D = read(), Q = read();
        for(int i = 1; i <= m; ++i)
            a[i] = read();
        for(int i = 1; i <= n; ++i){
            int k = read(), x = i + m;
            while(k --){
                int y = read(), z = read();
                add_edge(x, y, z);
                add_edge(y, x, z);
            }
        }
        // cerr << "YES" << endl;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dist[i][j] = (i == j ? 0 : inf);
        for(int i = 1; i <= m; ++i){
            int x, y;
            for(int j = head[i]; j; j = nxt[j])
                for(int k = nxt[j]; k; k = nxt[k]){
                    x = to[j] - m, y = to[k] - m;
                    // assert(x <= n && y <= n);
                    dist[x][y] = dist[y][x] = min(dist[x][y], w[j] + w[k]);
                }
        }
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        while(Q --){
            int s = read(), t = read();
            LL ans = inf;
            for(int i = head[s]; i; i = nxt[i])
                for(int j = head[t]; j; j = nxt[j])
                    ans = min(w[i] + w[j] + dist[to[i] - m][to[j] - m], ans);
            cout << ans + a[s] + a[t] << '\n'; 
        }
    }
    return 0;
}
/*
g++ subway.cpp -o subway.exe -O2
./checker
*/