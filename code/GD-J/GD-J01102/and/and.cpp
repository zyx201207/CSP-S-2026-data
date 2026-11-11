#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int M = 3e6 + 7;

int n, m, a[N], ans;
vector<int> w[40];
bitset<N> vis[32];

signed main() {
    // and
    freopen("and.in", "r", stdin);
    // freopen("and2.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j <= 30; j++) {
            if((a[i] >> j) & 1) {
                w[j].push_back(i);
                vis[j][i] = 1;
            }
        }
    }
    bitset<N> cur;
    for(int i = 1; i <= n; i++)
        cur[i] = 1;
    for(int i = 30; i >= 0; i--) {
        if((int)(cur & vis[i]).count() >= m) {
            cur &= vis[i];
            ans += (1 << i);
        }
    }
    cout << ans;
    return 0;
}
