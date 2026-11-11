#include <bits/stdc++.h>
#define ll long long
#define FILE(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;

int n;
ll D;

namespace sub1 {
    const int N = 5100;

    ll A[N];
    int dis[N];
    int flag[N];

    void MAIN() {
        for(int i = 1; i <= n; i++) cin >> A[i];
        int ans = 0;
        for(int r = n; r >= 1; r--) {
            int pos = r;
            memset(dis, 63, sizeof dis);
            memset(flag, 0, sizeof flag);
            dis[r] = 0;
            for(int l = r - 1; l >= 1; l--) {
                while(pos > l && A[pos] - A[l] > D) pos--;
                if(pos == l) break;
                dis[l] = dis[pos] + 1;

                // judge necc req
                if(flag[pos] == 2) flag[l] = 2;
                else if(flag[pos] == 1) {
                    if(dis[pos] != dis[pos - 1]) ans++, flag[l] = 1;
                    else flag[l] = 2;
                } else {
                    if((!flag[pos - 1]) && pos > l + 1 && dis[pos] == dis[pos - 1] && dis[pos - 2] != dis[pos]) ans++, flag[l] = 1;
                    else if(dis[pos] == dis[pos - 1]) flag[l] = 2;
                }
            }
        }
        cout << ans << '\n';
    }
}

namespace sub2 {
    const int N = 2000100;

    ll A[N];

    void MAIN() {
        for(int i = 1; i <= n; i++) cin >> A[i];
        ll dd = D / (A[2] - A[1]);
        if(dd > 1) cout << max(0ll, (ll)n - (dd * 2ll - 1ll)) << '\n';
        else cout << "0\n";
    }
}

namespace sub3 {
    const int N = 2000100;

    ll A[N];
    int L[N], R[N];

    void MAIN() {
        for(int i = 1; i <= n; i++) cin >> A[i];
        int pos = 1;
        for(int i = 1; i <= n; i++) {
            while(pos < n && A[pos + 1] - A[i] <= D) pos++;
            R[i] = pos;
        }
        pos = n;
        for(int i = n; i >= 1; i--) {
            while(pos > 1 && A[i] - A[pos - 1] <= D) pos--;
            L[i] = pos;
        }
        pos = 1;
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            while(pos <= n && R[i] - L[pos] > 1) pos++;
            if(pos <= n && R[i] - L[pos] == 1) ans += n - pos + 1;
        }
        cout << ans << '\n';
    }
}

int main() {
    FILE("migrate");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int cid, T_T; cin >> cid >> T_T;
    while(T_T--) {
        cin >> n >> D;
        if(n <= 5000) sub1::MAIN();
        else if(cid == 11 || cid == 12) sub2::MAIN();
        else if(cid == 13 || cid == 14) sub3::MAIN();
    }
    return 0;
}