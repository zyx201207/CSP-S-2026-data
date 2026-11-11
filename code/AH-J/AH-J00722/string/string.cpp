/*
my eye: easy
my mind: go go go!
my hand: ...
my coding: [shit]
*/
#include <bits/stdc++.h>
#define l first
#define c second
using namespace std;
using ll = long long;
using P = pair<ll, char>;

const int N = 2e5 + 10;
int n, tl, tr;
ll sum[N], ans, t;
P v[N];

int find(ll x) {
    int p = 0;
    for (int l = 1, r = n, mid; l <= r; ) {
        mid = (l + r) >> 1;
        if (x <= sum[mid]) r = mid - 1, p = mid;
        else l = mid + 1;
    }
    return p;
}

void solve() {
    // if () reverse(v + 1, v + 1 + n);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + v[i].l;
    }
    for (int i = n; sum[n] - sum[i - 1] <= sum[n] / 2; i--) {
        tl = find(sum[n] - sum[i] + v[i].l), tr = find(sum[n] - sum[i] + 1);
        // cout << v[tl].l << ' ' << v[tl].c << ' ' << v[tr].l << ' ' << v[tr].c;
        if (tl == tr) {
            if (v[tl].c != v[i].c) ans += v[i].l;
        } else {
            for (int j = tl; t <= tr; j++) {
                if (v[j].c != v[i].c) {
                    if (j != tl && j != tr) ans += v[j].l;
                    else if (j == tl)
                        ans += (sum[j + 1] - (sum[n] - sum[i] + v[i].l));
                    else if (j == tr)
                        ans += sum[j] + v[j].l - 1 - (sum[n] - sum[i] + 1) + 1;
                }
            }
        }
    }
    cout << ans;
    return ;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].l >> v[i].c;
        if (v[i].l > 50) flag = 0;
    }
    if (n == 1) { cout << 0; return 0; }
    if (n <= 2000 && flag) {
        string s;
        for (int i = 1; i <= n; i++) {
            for (ll j = 1; j <= v[i].l; j++) s += v[i].c;
        }
        int L = (int)s.size();
        if (L % 2) {
            for (int i = L / 2 - 1, j = L / 2 + 1; i >= 0; i--, j++) {
                ans += (s[i] != s[j]);
            }
        } else {
            for (int i = L / 2 - 1, j = L / 2; i >= 0; i--, j++) {
                ans += (s[i] != s[j]);
            }
        }
        cout << ans;
    } else solve();
    return 0;
}
