#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define CONTEST

const int inf = 2e18;
void solve() {
    struct Node {
        int first, second, third;
        Node(int fir, int sec, int thi) : first(fir), second(sec), third(thi) {}
        void insert(int x) {
            if (x <= first) third = second, second = first, first = x;
            else if (x <= second) third = second, second = x;
            else if (x <= third) third = x; 
        }
        void insert(Node x) {
            insert(x.first);
            insert(x.second);
            insert(x.third);
        }
    };  
    auto adddd = [](Node x) -> Node {
        return {x.first + 1, x.second + 1, x.third + 1};
    };
    int n, d; cin >> n >> d;
    vector<int> x(n);
    for (int i = 0; i < n; i++) 
        cin >> x[i];
    int cnt = 0;
    for (int s = 0; s < n; s++) {
        vector<Node> f(n, {inf, inf, inf});
        f[s] = {0, inf, inf};
        for (int i = s + 1; i < n; i++) {
            for (int j = i - 1; j >= s; j--) {
                if (x[i] - x[j] > d) break;
                f[i].insert(adddd(f[j]));
            }
            // cerr << s << " to " << i << " : " << f[i].first << " " << (f[i].second == inf ? -1 : f[i].second) << " " << (f[i].third == inf ? -1 : f[i].third) << endl;
            if (f[i].first == f[i].second && f[i].first != f[i].third && f[i].first != inf) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
signed main() {
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    #endif
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);
    int c; cin >> c;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;   
}
// CSP-S 2026 RP++