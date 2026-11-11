#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 505;
const int M = 5e5 + 5;
const int inf = 1e18;
int c, n, m, d, q, w[M], a[N][N];
vector<pair<int, int> > g[M + N];
inline int read(){
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = getchar();
    }
    return s;
}
inline void print(const int &x){
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1;i <= m;i++){
        w[i] = read();
	}
	for (int i = 1;i <= n;i++){
        int k = read();
        for (int j = 1;j <= k;j++){
            int v = read(), t = read();
            g[i + m].push_back({v, t});
            g[v].push_back({i + m, t});
        }
	}
	for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            a[i][j] = (i == j ? 0 : inf);
        }
	}
	for (int i = 1;i <= m;i++){
        int siz = g[i].size();
        for (int j = 0;j < siz;j++){
            for (int k = j + 1;k < siz;k++){
                a[g[i][j].first - m][g[i][k].first - m] = min(a[g[i][j].first - m][g[i][k].first - m], g[i][j].second + g[i][k].second);
                a[g[i][k].first - m][g[i][j].first - m] = min(a[g[i][k].first - m][g[i][j].first - m], g[i][j].second + g[i][k].second);
            }
        }
	}
	for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
	}
	while (q--){
        int u = read(), v = read();
        int ans = inf;
        for (auto p1 : g[u]){
            for (auto p2 : g[v]){
                ans = min(ans, a[p1.first - m][p2.first - m] + p1.second + p2.second);
            }
        }
        print(ans + w[u] + w[v]);
        putchar('\n');
	}
	return 0;
}
