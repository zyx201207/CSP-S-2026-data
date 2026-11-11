#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

using ll = long long;

struct Node {
    ll l;
    mutable ll r;
    mutable char v;
    Node(ll l, ll r, char v) : l(l), r(r), v(v) {}
    bool operator<(const Node& other) const {
        return l < other.l;
    }
};

set<Node> odt;

auto split(ll x) {
    auto p = prev(odt.upper_bound(Node(x, 0, 0)));
    if (p->l == x) return p;
    if (p->r < x) return odt.end();
    auto [l, r, v] = *p;
    odt.erase(p);
    odt.emplace(l, x - 1, v);
    return odt.emplace(x, r, v).first;
}
ll assign(ll l, ll r, char v) {
    auto pr = split(r + 1), pl = split(l);
    ll res = 0;
    for (auto it = pl; it != pr; it++) if (it->v != v) res += it->r - it->l + 1;
    odt.erase(pl, pr);
    odt.emplace(l, r, v);
    return res;
}

int n, t;
char c, last;
ll leng = 0, ans = 0, mid;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> c;
        if (i != 0 && c == last) prev(odt.end())->r = leng + t - 1;
        else odt.emplace(leng, leng + t - 1, c);
        last = c;
        leng += t;
    }
    auto it_mid = split(mid = (leng >> 1) + (leng & 1) - 1);
    for (auto it = odt.begin(); it != it_mid; it++) ans += assign(leng - it->r - 1, leng - it->l - 1, it->v);
    if ((mid & 1)) ans += assign(leng - it_mid->r - 1, leng - it_mid->l - 1, it_mid->v);
    cout << ans;
    return 0;
}

