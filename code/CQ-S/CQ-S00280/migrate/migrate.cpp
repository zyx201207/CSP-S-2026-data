#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;

int main() {
    freopen("migrate.in", "r", stdin);  freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll testcase, t; cin >> testcase >> t;
    while (t--) {
        ll n, d; cin >> n >> d;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        if (n <= 300) {
            ll ans = 1e18;
            auto dfs = [&](auto &&self, ll x, vector<ll> &p, ll r, ll stp) -> void {
                if (x == r) {ans = min(ans, stp); return;}
                if (stp >= ans) return;

                ll to_ = x, res = 0;
                while (1) {if (to_ > r) break; res += p[to_]; if (res > d) break; to_++; self(self, to_, p, r, stp + 1);}
            };

            ll cnt = 0;
            auto dfs1 = [&](auto &&self, ll x, vector<ll> &p, ll r, ll stp) -> void {
                if (x == r) {if (stp == ans) cnt++; return;}
                if (stp >= ans) return;

                ll to_ = x, res = 0;
                while (1) {if (to_ >= r) break; res += p[to_]; if (res > d) break; to_++; self(self, to_, p, r, stp + 1);}
            };

            ll ans_ = 0;
            for (int l = 1; l <= n; l++) for (int r = l; r <= n; r++) {
                vector<ll> p; for (int k = l; k <= r; k++) p.push_back(a[k]);
                vector<ll> s; s.push_back(0); for (int k = 1; k < p.size(); k++) s.push_back(p[k] - p[k - 1]);
                // cerr << "l = " << l << ", r = " << r << endl;
                // for (int k = 1; k <= r - l; k++) cerr << d[k] << ' ';
                // cerr << endl;
                ans = 1e18; dfs(dfs, 1, s, r - l + 1, 0); cnt = 0; dfs1(dfs1, 1, s, r - l + 1, 0); ans_ += (cnt == 2);
                // if (cnt == 2) cerr << l << ' ' << r << endl;
                nxt:;
            }

            cout << ans_ << endl; continue;
        }

        vector<ll> s; s.push_back(0);
        for (int i = 2; i <= n; i++) s.push_back(a[i] - a[i - 1]);
        bool flag = 0; for (int i = 1; i < s.size(); i++) if (d <= s[i]) {flag = 1; break;}
        if (flag) {cout << 0 << endl; continue;}
        ll sum = 0;
        for (int i = 1; i < s.size(); i++) sum += s[i]; if (sum <= d) {cout << 0 << endl; continue;}

        ll cnt = 0, x = 0;
        for (int i = 1; i < s.size(); i++) {x += s[i]; if (x > d) break; cnt++;}
        // cerr << "cnt = " << cnt << endl;

        cout << n - (cnt + cnt - 1) << endl;
    }
    return 0;
}






















// 双径岛屿对？双缩脲试剂！
// 电视
// 表白
// 妈妈
// 爱
// CCF
// fuck
// 草