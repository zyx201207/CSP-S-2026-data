#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void getcuts(const vector<pair<int, char>>& ls, vector<ll>& res) {
    ll tot = 0;
    for (auto [cnt, ch] : ls) {
        tot += cnt;
        res.emplace_back(tot);
    }
}
inline vector<tuple<ll, char, char>> charls(const vector<pair<int, char>>& l, const vector<pair<int, char>>& r, const vector<ll>& cuts) {
    // returns len, left, right
    char curc_l = '@', curc_r = '@';
    ll ltot = 0, rtot = 0;
    int nextl = 0, nextr = 0;
    ll lastcut = 0;
    vector<tuple<ll, char, char>> ret;
    for (auto x : cuts) {
        if (ltot < x) {
            ltot += l[nextl].first;
            curc_l = l[nextl].second;
            ++nextl;
        }
        if (rtot < x) {
            rtot += r[nextr].first;
            curc_r = r[nextr].second;
            ++nextr;
        }
        ret.emplace_back(x - lastcut, curc_l, curc_r);
        lastcut = x;
    }
    return ret;
}
inline ll getans(const vector<tuple<ll, char, char>>& ls) {
    ll ans = 0;
    for (auto [len, c1, c2] : ls) {
        if (c1 != c2) {
            ans += len;
        }
    }
    return ans;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    ll totlen = 0;
    vector<pair<int, char>> ls(n);
    for (int i = 1; i <= n; ++i) {
        cin >> ls[i - 1].first >> ls[i - 1].second;
        totlen += ls[i - 1].first;
    }
    ll mid = totlen / 2;
    ll tmp = 0;
    vector<pair<int, char>> l, r;
    for (auto [cnt, ch] : ls) {
        auto orig_tmp = tmp;
        tmp += cnt;
        if (tmp > mid) {
            if (r.size() == 0) {
                if (mid != orig_tmp) {
                    l.emplace_back(mid - orig_tmp, ch);
                }
                r.emplace_back(tmp - mid - (totlen % 2 == 1 ? 1 : 0), ch);
            } else {
                r.emplace_back(cnt, ch);
            }
        } else {
            l.emplace_back(cnt, ch);
        }
    }
    reverse(l.begin(), l.end());
    vector<ll> cuts;
    getcuts(l, cuts);
    getcuts(r, cuts);
    sort(cuts.begin(), cuts.end());
    cuts.erase(unique(cuts.begin(), cuts.end()), cuts.end());
    auto cls = charls(l, r, cuts);
    cout << getans(cls) << '\n';
    return 0;
}