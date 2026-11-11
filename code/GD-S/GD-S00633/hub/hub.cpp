#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <queue>
using namespace std;
using ui32 = unsigned int;
using big = long long;
using ui64 = unsigned big;
using bigf = long double;
constexpr const big INF = 1e18;
constexpr const big mod = 998244353;
constexpr const bigf EPS = 1e-8;

constexpr const int N = 4e4 +5;

void solve() {

}

vector<int> T[N];
int f[N], CUT1, CUT2;
void dfs(int u, int fa) {
    f[u] = fa;
    for(int v : T[u]) {
        if(v!=fa) dfs(v, u);
    }
}

int dis[N];
void dfs_dis(int u, int fa) {
    dis[u] = dis[fa]+1;
    for(int v : T[u]) {
        if(u==CUT1&&v==CUT2) continue;
        if(v==fa) continue;
        dfs_dis(v, u);
    }
}

void solve1() {

}
// 50pts

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int c, t; cin >> c >> t;
    while (t--) {
        solve1();
    }
    return 0;
}
