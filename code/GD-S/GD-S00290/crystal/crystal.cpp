#include <bits/stdc++.h>
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define rrep(i,j,k) for (int i = (j); i >= (k); i--)
#define orep(i,j,k) for (int i = (j); i < (k); i++)
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <class T>
using vec = vector<T>;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll m;
    cin >> n >> m;
    vec<ll> a(n);
    rep(i, 0, n-1)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll c = 0, tot = 0, ans = 0;
    queue<ll> q;
    rep(i, 0, n-1) {
        q.push(a[i]), c++, tot += a[i];
        while (c * a[i] - tot > m) {
            c--, tot -= q.front();
            q.pop();
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
}