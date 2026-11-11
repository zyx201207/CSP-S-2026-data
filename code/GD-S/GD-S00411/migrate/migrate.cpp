#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 2000005
#define INF 0x3f3f3f3f3f3f3f3f

int cid, t, n, d; int x[MAXN], f[MAXN], g[MAXN], h[MAXN], R[MAXN];

signed main(){
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (cin >> cid >> t; t; --t){
        cin >> n >> d; for (int i(1); i<=n; ++i) cin >> x[i]; int ans(0);
        x[0] = -INF; x[n+1] = INF;
        for (int i(n), p(n+1); i; --i){for (; p>i && x[p]-x[i]>d; --p); R[i] = p;}
        for (int i(1); i<=n; ++i){
            ++g[i]; if (R[i] != i){if (x[R[i]]-x[i-1] > d) g[R[i]] += g[i]; else ++g[R[i]];}
            if (R[i]-i >= 2){
                if (x[R[i]-1]-x[i-1] > d) f[R[i]] += g[i]; else ++f[R[i]];
            }
            if (f[i]){
                int l(max(R[i-2], i)+1), r(min(R[i]-1, R[i-1])); ans += max(r-l+1, 0ll)*f[i];
                if (R[i] != i && R[i] == R[i-1] && R[i-1] != R[i-2]){
                    h[R[i]] += f[i];
                }
            }
            if (h[i]){
                ans += h[i];
                if (R[i] != i && x[R[i]]-x[i-1] > d) h[R[i]] += h[i];
                int l(R[i-1]+1), r(R[i]-1); ans += max(r-l+1, 0ll)*h[i];
            }
        }
        cout << ans << '\n'; fill(f, f+n+2, 0); fill(g, g+n+2, 0); fill(h, h+n+2, 0);
    }

    return 0;
}

/*
2 6
2 7
2 8
2 9
3 6
3 7
3 8
3 9
4 10
4 11
4 12
5 10
5 11
5 12
6 10
6 11
6 12
7 10
7 11
7 12
0 0 0 0 0 2 2 2 2 4 4 4 0
*/