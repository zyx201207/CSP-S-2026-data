// and
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 1023;
int n, m;
vector<int> s;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        s.push_back(x);
    }
    for (int i = 30; i >= 0; --i) {
        vector<int> ns;
        ns.clear();
        for (int x : s)
            if (x & (1 << i))
                ns.push_back(x);
        if (ns.size() >= m) s = ns;
    }
    int ans = (1 << 30) - 1;
    for (int x : s) ans &= x;
    cout << ans << '\n';
    return 0;
}
