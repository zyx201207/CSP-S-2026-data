#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 2e5 + 5, M = 1 << 5;
bool vis[N];
int n, m, a[N], b[M][N], len[N], p2[M], ans;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int x = a[i];
        while(x) {
            b[len[i]++][i] = x & 1;
            x >>= 1;
        }
    }
    p2[0] = 1;
    for(int i = 1; i <= 30; i++) p2[i] = p2[i - 1] << 1;
    memset(vis, true, sizeof vis);
    for(int i = 30; i >= 0; i--) {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(vis[j] && b[i][j]) cnt++;
        if(cnt >= m) {
            ans += p2[i];
            for(int j = 1; j <= n; j++) vis[j] &= b[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}