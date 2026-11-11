#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int c, T, n, d;
int x[2000010], cnt1[2000010], R[2000010];
int cnt2[2000010], L[2000010];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--) {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i], cnt1[i] = cnt2[i] = 0;
        int r = 1;
        for(int i = 1; i <= n; i++) {
            while(r <= n && x[r] - x[i] <= d) ++r;
            R[i] = r - 1;
        }
        for(int i = n; i >= 1; i--) {
            cnt1[i] = cnt1[R[i]] + (R[i] - i + 1) - (R[i - 1] - i + 1);
        }
        for(int i = 1; i <= n; i++) cnt1[i] += (R[i - 1] - i + 1);
        for(int i = 1; i <= (n >> 1); i++) swap(x[i], x[n - i + 1]), x[i] = -x[i], x[n - i + 1] = -x[n - i + 1];
        if(n & 1) x[(n >> 1) + 1] = -x[(n >> 1) + 1];
        r = 1;
        for(int i = 1; i <= n; i++) {
            //cerr << x[i] << ' ';
            while(r <= n && x[r] - x[i] <= d) ++r;
            L[i] = (r - 1);
        }
        //cerr << '\n';
        for(int i = n; i >= 1; i--) {
            cnt2[i] = cnt2[L[i]] + (L[i] - i + 1) - (L[i - 1] - i + 1);
        }
        for(int i = 1; i <= n; i++) cnt2[i] += (L[i - 1] - i + 1);
        for(int i = 1; i <= n; i++) L[i] -= i, L[i]++;
        for(int i = 1; i <= (n >> 1); i++) swap(x[i], x[n - i + 1]), swap(L[i], L[n - i + 1]), swap(cnt2[i], cnt2[n - i + 1]);
        for(int i = 1; i <= n; i++) L[i] = i - L[i] + 1;
        //for(int i = 1; i <= n; i++) cerr << L[i] << ' ' << R[i] << ' ' << cnt1[i] << ' ' << cnt2[i] << '\n';
        //cerr << '\n';
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(R[i] == i || R[i] == i + 1) continue;
            int lf = max(R[i] + 1, R[R[i] - 2] + 1);
            int rg = R[R[i] - 1];
            //cerr << i << ' ' << lf << ' ' << rg << '\n';
            if(rg < lf) continue;
            if(R[rg - 1] == rg) {
                if(L[i + 1] == i) ans += cnt2[i] * cnt1[rg], ans += cnt2[i] * (rg - lf);
                else ans += cnt1[rg], ans += rg - lf;
                //cerr << "f " << ans << '\n';
                continue;
            }
            if(L[i + 1] == i) ans += (rg - lf + 1) * cnt2[i];
            else ans += (rg - lf + 1);
            //cerr << ans << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}