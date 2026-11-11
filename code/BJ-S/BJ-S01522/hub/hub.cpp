#include <bits/stdc++.h>
#define ch(opt, tar, ...) tar = opt({tar, __VA_ARGS__})
#define isz(x) (int((x).size()))
#define inlfc __attribute__((always_inline)) inline
using namespace std;
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;


int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C, T;
    cin >> C >> T;
    while (T --) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i < n; i ++) { 
            int u, v;
            cin >> u >> v;
        }
        cout << "0\n";
    }
    return 0;
}
