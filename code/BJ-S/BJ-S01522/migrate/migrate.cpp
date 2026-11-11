#include <bits/stdc++.h>
#define ch(opt, tar, ...) tar = opt({tar, __VA_ARGS__})
#define isz(x) (int((x).size()))
#define inlfc __attribute__((always_inline)) inline
using namespace std;
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;

constexpr int INF = 1e9;
constexpr ll INFLL = 2e18;

/*
template<typename T>
inlfc void read(T &x) {
    x = 0;
    char ch;
    bool neg = 0;
    while ((ch = getchar_unlocked()) && (ch < '0' || ch > '9') && ch != '-');
    if (ch == '-') neg = 1;
    do (x *= 10) += ch - '0';
    while ((ch = getchar_unlocked()) && '0' <= ch && ch <= '9');
    if (neg) x = -x;
}*/

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C, T;
    cin >> C >> T;
    while(T --) {
        int n;
        ll d, ans = 0;
        cin >> n >> d;
        vector<ll> x(n + 1);
        vector<int> left(n + 1);
        vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
        for (int i = 1, j = 1; i <= n; i ++) {
            cin >> x[i];
            dis[i][i] = 0;
            while (j < i && x[i] - x[j] > d) j ++;
            left[i] = j;
        }
        for (int len = 2; len <= n; len ++)
            for (int l = 1, r = len; r <= n; l ++, r ++)
                dis[l][r] = dis[l][max(left[r], l)] == INF ?
                            INF : dis[l][max(left[r], l)] + 1;
        for (int len = 2; len <= n; len ++)
            for (int l = 1, r = len; r <= n; l ++, r ++) {
                int cnt = 0;
                if (dis[l][r] == INF) continue;
                for (int k = max(left[r], l); k < r; k ++)
                    if (dis[l][k] + dis[k][r] <= dis[l][r])
                        cnt ++;
                ans += (cnt == 2);
            }
        printf("%lld\n", ans);
    }
    return 0;
}
