#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<ll, pair<char, char>>> w;
    vector<pair<ll, char>> v;
    ll tol = 0;
    while (n--) {
        ll cnt; char ch;
        cin >> cnt; cin >> ch;
        v.push_back(make_pair(cnt, ch));
        tol += cnt;
    }
    int len = v.size();
    int l = -1, r = len;
    ll ltol = 0, rtol = 0, xltol = 0, xrtol = 0;
    while (l < len && r >= 0) {
        if (ltol > rtol) {
            r--;
            auto lrdis = make_pair(v[l].second, v[r].second);
            rtol += v[r].first;
            w.push_back(make_pair(min(rtol, ltol) - xrtol, lrdis));
        }
        else if (ltol == rtol) {
            l++, r--;
            auto lrdis = make_pair(v[l].second, v[r].second);
            ltol += v[l].first;
            rtol += v[r].first;
            w.push_back(make_pair(min(rtol, ltol) - xltol, lrdis));
        }
        else {
            l++;
            auto lrdis = make_pair(v[l].second, v[r].second);
            ltol += v[l].first;
            w.push_back(make_pair(min(rtol, ltol) - xltol, lrdis));
        }
        xltol = ltol, xrtol = rtol;
    }
    ll ans = 0; ltol = 0;
    for (auto p : w) {
        ltol += p.first;
        if (ltol > tol / 2) break;
        if (p.second.first != p.second.second && p.first > 0) ans += p.first;
    }
    cout << ans;
    return 0;
}
