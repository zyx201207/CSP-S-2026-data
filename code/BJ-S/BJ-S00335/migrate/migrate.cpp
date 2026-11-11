#include<bits/stdc++.h>
#define int long long
#define fo(i, l, r) for(int i = (l); i <= (r); ++i)
using namespace std;
const int N = 2000005, INF = 1000000000000000000ll;
int c, T, n, d, x[N], f[N], g[N], sum[N], t[N << 2];
void build(int p, int l, int r){
    if(l == r) return t[p] = n, void();
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    t[p] = min(t[p << 1], t[p << 1 | 1]);
    return;
}
void modify(int p, int l, int r, int x, int k){
    if(x < l || x > r) return;
    if(l == r) return t[p] = k, void();
    int mid = (l + r) >> 1;
    modify(p << 1, l, mid, x, k), modify(p << 1 | 1, mid + 1, r, x, k);
    t[p] = min(t[p << 1], t[p << 1 | 1]);
    return;
}
int query(int p, int l, int r, int ql, int qr){
    if(r < ql || qr < l) return n;
    if(ql <= l && r <= qr) return t[p];
    int mid = (l + r) >> 1;
    return min(query(p << 1, l, mid, ql, qr), query(p << 1 | 1, mid + 1, r, ql, qr));
}
signed main(){
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> T; while(T--){
        cin >> n >> d; fo(i, 1, n) cin >> x[i];
        int ans = 0;
        fo(i, 1, n){
            fo(j, 1, n) f[j] = n, g[j] = 0, sum[j] = 0;
            f[i] = 0, g[i] = sum[0] = 1;
            build(1, 1, n), modify(1, 1, n, i, 0);
            int res = i;
            fo(j, i + 1, n){
                while(res < j && x[j] - x[res] > d){
                    sum[f[res]] -= g[res];
                    res++;
                }
                f[j] = query(1, 1, n, res, j - 1) + 1, modify(1, 1, n, j, f[j]);
                g[j] = sum[f[j] - 1], sum[f[j]] += g[j];
                if(g[j] == 2) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
// g++ migrate.cpp -o migrate -O2 -std=c++14 -static