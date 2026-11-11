#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5000 + 10;
int c, t, n, d, a[maxn], f[maxn][maxn], len[maxn][maxn], dif;
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    if(11 <= c && c <= 12) {
        while(t--) {
            cin >> n >> d;
            for(int i = 1; i <= n; i++) cin >> a[i];
            dif = a[2]-a[1];
            if(d<=dif) cout << "0\n";
            else cout << max(0LL, n-d/dif*2+1) << "\n";
        }
        return 0;
    }
    while(t--) {
        memset(f, 0, sizeof(f));
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for(int l = 1; l <= n; l++) {
            f[l][l] = 1;
            len[l][l] = 1;
            int k = 1, mlen = 1, sumf = 1;
            for(int r = l+1; r <= n; r++) {
                len[l][r] = 1e18;
                for(int k = r-1; a[r]-a[k]<=d && k >= l; k--) {
                    if(len[l][r] > len[l][k]+1) {
                        len[l][r] = len[l][k]+1;
                        f[l][r] = f[l][k];
                    } else if(len[l][r] == len[l][k]+1) f[l][r] += f[l][k];
                }
                if(f[l][r] == 2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}