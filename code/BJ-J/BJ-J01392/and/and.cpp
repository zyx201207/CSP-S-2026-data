#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 25, maxlog = 32;
bitset<maxn> selected;
unsigned arr[maxn], ans = 0;
int n, m, bkt[2];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        selected[i] = true;
        cin >> arr[i];
    }
    for (int i = maxlog - 1; i >= 0; --i) {
        memset(bkt, 0, sizeof(bkt));
        for (int k = 1; k <= n; ++k) {
            if (selected[k]) {
                ++bkt[arr[k] >> unsigned(i) & 1];
            }
        }
        if (bkt[1] >= m) {
            ans |= (1u << i);
            for (int k = 1; k <= n; ++k) {
                if ( selected[k] && ( (arr[k] >> unsigned(i) & 1) == 0 ) ) {
                    selected[k] = false;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}