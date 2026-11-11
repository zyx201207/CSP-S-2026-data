#include <bits/stdc++.h>
#define loop(i, a, b) for(int i = (a); i <= (b); i++)
#define rloop(i, a, b) for(int i = (a); i >= (b); i--)
#define lowbit(x) ((x) & (-(x)))
typedef long long ll;
using namespace std;
const int N = 2e6 + 5;
const ll INF = 1e18;

ll n, m, tot, fa[N], siz[N];
ll a[N], b[N], sz[N], d;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return ;
    fa[fx] = fy, siz[fy] += siz[fx];
}
void init() {
    loop(i, 1, n + 1) fa[i] = i, siz[i] = 1;
}
void solve() {
    cin >> n >> d;
    loop(i, 1, n) cin >> a[i];
    init();
    loop(i, 1, n - 1) {
        ll x = a[i];
        ll idx = upper_bound(a + 1, a + n + 1, (x + d)) - a;
        //cout << idx << "\n";
        if(idx == i + 1 && a[i + 1] - a[i] <= d) merge(i, i + 1);
    }
    tot = 1, b[1] = 0, sz[1] = find(1);
    loop(i, 1, n) if(fa[i] == i) {
        sz[tot] = siz[i];
        if(i == n) break;
        tot++;
        b[tot] = b[tot - 1] + a[i + 1] - a[i];
        sz[tot] = siz[find(i + 1)];
    }
    ll ans = 0;
     
    //cout << tot << "\n";
    loop(i, 4, tot) {
        int s1 = b[i] - b[i - 1], s2 = b[i - 1] - b[i - 2], s3 = b[i - 2] - b[i - 3];
        if((s1 + s2 <= d && s1 + s2 + s3 > d && s3 <= d) && (s1 <= d && s2 + s3 <= d && s1 + s2 + s3 > d)) ans += sz[i] * sz[i - 3];
    }
    cout << ans << "\n";
    
}
//Oct31==Dec25?

signed main() {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int c, t; cin >> c >> t; while(t--) solve();
    return 0;
    
}
//g++ subway.cpp -o a -O2 -static -std=c++14
//./a
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

