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
#define UP(x,y,z) for (int x = y; x <= z; ++x)
int c;
namespace imc {
    constexpr int N = 2e6 + 3;
    int n; ll d, a[N];
    int l[N], r[N]; ll cnt[N], f[N];
    void main() {
        cin >> n >> d;
        UP(i,1,n) cin >> a[i];
        l[0] = r[0] = 1;
        UP(i,1,n) {
            l[i] = l[i-1], r[i] = r[i-1];
            while (r[i] < n && a[r[i] + 1] - a[i] <= d) ++r[i];
            while (- a[l[i]] + a[i] > d) ++l[i];
            // cerr << i << ' ' << l[i] << ' ' << r[i] << '\n';
        }
        ll ans = 0;
        UP(i,1,n) {
            fill(cnt,cnt+1+n,0);
            fill(f,f+1+n,0); f[i] = 1, f[i+1] = -1;
            int L = i, R = i;
            while (1) {
                // cerr << L << ' ' << R << '\n';
                int nxL = R + 1, nxR = r[R];
                if (nxR == R) {
                    UP(j,L,R) f[j] += f[j-1], cnt[j] = f[j];
                } else {
                    UP(j,L,R) {
                        f[j] += f[j-1], cnt[j] = f[j];
                        if (r[j] >= nxL)
                            f[nxL] += cnt[j], f[r[j]+1] -= cnt[j];
                    }
                }
                bool valid = false;
                UP(j,L,R) {
                    ans += (cnt[j] == 2);
                    if (cnt[j] <= 2) valid = true;
                }
                if (!valid) break;
                L = nxL, R = nxR;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> c >> T;
    while (T--) {
        imc::main();
    }
}