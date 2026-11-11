#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n;
ll ans;
vector<pair<ll, char> > v;
string s;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll cnt;
        char c;
        cin >> cnt >> c;
        v.push_back({cnt, c});
    }
    for (int i = 0, j = n - 1; i <= j;) {
        if (i == j) break;
        if (v[i].second == v[j].second) {
            if (v[i].first < v[j].first) {
                v[j].first -= v[i].first;
                v[i].first = 0;
            } else {
                v[i].first -= v[j].first;
                v[j].first = 0;
            }
        } else {
            if (v[i].first < v[j].first) {
                ans += v[i].first;
                v[j].first -= v[i].first;
                v[i].first = 0;

            } else {
                ans += v[j].first;
                v[i].first -= v[j].first;
                v[j].first = 0;

            }
        }
        if (v[i].first == 0) i++;
        if (v[j].first == 0) j--;
    }
    cout << ans << "\n";
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
