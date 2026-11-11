#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2000005;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
int c, t, n, d, x[N];
int rr[N], ll[N], f[N], snf[N], dnf[N], ss[N], sl[N];

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> c >> t;
    while(t--){
        int ans = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i ++)
            cin >> x[i];
        for(int i = 1; i <= n; i ++)
            rr[i] = 1;
        int r = 1, l = 1;
        for(l = 1; l <= n; l ++){
            while(r < n && x[r+1] - x[l] <= d){
                r ++;
            }
            rr[l] = r, ll[r];
        }
        for(int i = 1; i <= n; i ++){
            int r1 = rr[i];
            int r2 = rr[r1];
            if(i == r1 || r1 == r2)
                f[i] = 0;
            else if(r1 == i + 1)
                f[i] = 1;
            else if(r1 == i + 2){
                if(rr[r1-1] == r2)
                    f[i] = 2;
                else
                    f[i] = 1;
            }else{
                if(rr[r1-1] != r2)
                    f[i] = 1;
                else if(rr[r1-2] != r2)
                        f[i] = 2;
                else
                    f[i] = 0;
            }
        }
        for(int i = 1; i <= n; i ++){
            int r1 = rr[i];
            int r2 = rr[r1];
            snf[i] = 0;
            if(i == r1 || r1 == r2)
                snf[i] = 0;
            else
                snf[i] = r2 - rr[r1-1];
        }
        for(int i = 1; i <= n; i ++){
            int r1 = rr[i];
            int r2 = rr[r1];
            dnf[i] = 0;
            if(i == r1 || r1 == r2)
                continue;
            if(r1 == i + 1)
                dnf[i] = 0;
            else
                dnf[i] = rr[r1-1] - rr[r1-2];
        }
        for(int i = n; i >= 1; i --){
            int r1 = rr[i];
            int r2 = rr[r1];
            ss[i] = 0;
            if(i == r1 || r1 == r2)
                continue;
            ss[i] += snf[i];
            if(f[i] == 1)
                ss[i] += ss[r1];
        }
        for(int i = 1; i <= n; i ++)
            sl[i] = 0;
        for(int i = 1; i <= n; i ++){
            int r1 = rr[i];
            int r2 = rr[r1];
            if(i == r1 || r1 == r2)
                continue;
            if(f[i] == 1){
                sl[r2] = sl[r1] + 1;
            }
        }
        for(int i = 1; i <= n; i ++){
            int r1 = rr[i];
            int r2 = rr[r1];
            if(f[i] != 2)
                continue;
            ans += (sl[r1] + 1) * ss[r1];
        }
        for(int i = 1; i <= n; i ++){
            int r1 = rr[i];
            int r2 = rr[r1];
            if(i == r1 || r1 == r2)
                continue;
            ans += dnf[i] * (sl[r1] + 1);
        }
        cout << ans << endl;
        //if(t == 1){
         //   cout << n << d << endl;
         //   for(int i = 1; i <= n; i ++)
          //      cout << dnf[i] << ' ';
          //  cout << endl;
        //}
    }
    return 0;
}
