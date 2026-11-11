#include <bits/stdc++.h>
#define filename "subway"
using namespace std;

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>

template<class T> bool vmax(T &a, const T &b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, const T &b) { return b < a ? (a = b, 1) : 0; }

const int N = 5e5 + 5;

signed Case;

#define int long long 

int n, m, w[N], d, q;
vector<pii> vec[N];

int f[505][505];

void WaterM() {
    cin >> n >> m >> d >> q;
    upw(i, 1, m) scanf("%lld", &w[i]);
    upw(i, 1, n) {
        int k; scanf("%lld", &k);
        upw(round, 1, k) {
            int a, t; scanf("%lld%lld", &a, &t);
            vec[a].emplace_back(i, t);
        }
    }

    upw(i, 1, n) upw(j, 1, n) f[i][j] = Linf;
    upw(i, 1, n) f[i][i] = 0;
    upw(u, 1, m) {
        int sz = vec[u].size();
        upw(a, 0, sz - 1) {
            int i = vec[u][a].first, x = vec[u][a].second;
            upw(b, a + 1, sz - 1) {
                int j = vec[u][b].first, y = vec[u][b].second;
                vmin(f[i][j], x + y);
                vmin(f[j][i], x + y);
            }
        }
    }
    upw(k, 1, n) upw(i, 1, n) upw(j, 1, n) vmin(f[i][j], f[i][k] + f[k][j]);
    
    upw(round, 1, q) {
        int x, y; scanf("%lld%lld", &x, &y);
        int ans = Linf;
        for(auto e1 : vec[x]) {
            int i = e1.first, t1 = e1.second;
            for(auto e2 : vec[y]) {
                int j = e2.first, t2 = e2.second;
                vmin(ans, t1 + t2 + f[i][j]); 
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
}

signed main() {
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
    signed _ = 1;
    scanf("%d", &Case);
    // scanf("%d", &_);
    upw(round, 1, _) WaterM();
    return 0;
}