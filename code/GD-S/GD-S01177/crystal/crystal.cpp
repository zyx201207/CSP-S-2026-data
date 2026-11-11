#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T> void chkmax(T &x, T y) {if (x < y) x = y;}
template<typename T> void chkmin(T &x, T y) {if (x > y) x = y;}

namespace imc {
    void main() {
        int n; ll m; cin >> n >> m;
        vector<ll> a(n + 1), suf(n+2);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a.begin() + 1, a.end());
        for (int i = n; i >= 1; --i) suf[i] = suf[i+1] + a[i];
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int lo = 0, hi = i + 1;
            while (lo + 1 != hi) {
                int mid = (lo + hi) >> 1;
                if (m + (suf[i-mid+1] - suf[i+1]) < a[i] * mid) hi = mid;
                else lo = mid;
                // cerr << "check: " << i << ' ' << m + suf[i-mid+1] - suf[i+1] << '\n';
            }
            chkmax(ans, lo);
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // freopen("crystal1.out","w",stdout);s
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        imc::main();
    }
}