#include<bits/stdc++.h>
using namespace std;
typedef long lng;
const int maxn = 5e2 + 4, maxm = 5e5 + 10;
int n, m, q, w[maxm];
lng dp[maxn][maxn];
vector<pair<int, int> > go[maxm];
void Floyd() {
    for(int k = 1; k <= n; k ++) 
        for(int i = 1; i <= n; i ++) 
            for(int j = 1; j <= n; j ++) 
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[j][k]);
}
int read() {
    int x = 0;
    char ch = getchar();
    while(!isdigit(ch)) 
        ch = getchar();
    while(isdigit(ch)) 
        x = x * 10 + (ch - '0'), ch = getchar();
    return x;
}
void write(lng x) {
    if(x > 9) 
        write(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, d;
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; i ++) 
        w[i] = read();
    for(int i = 1; i <= n; i ++) {
        int k = read();
        for(int j = 1; j <= k; j ++) {
            int a = read(), t = read();
            go[a].push_back({i, t});
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i ++) 
        dp[i][i] = 0;
    for(int i = 1; i <= m; i ++) 
        for(pair<int, int> u : go[i]) 
            for(pair<int, int> v : go[i]) 
                if(u != v) 
                    dp[u.first][v.first] = dp[v.first][u.first] = min(dp[u.first][v.first], 1l * u.second + v.second);
    Floyd();
    while(q --) {
        int u, v;
        cin >> u >> v;
        lng ans = numeric_limits<lng>::max();
        for(pair<int, int> u_ : go[u]) 
            for(pair<int, int> v_ : go[v]) 
                ans = min(ans, dp[u_.first][v_.first] + u_.second + v_.second);
        write(ans + w[u] + w[v]);
        putchar('\n');
    }
    return 0;
}