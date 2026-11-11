#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int n, c, T, pre[N], nxt[N];
ll d, x[N], f[N], g[N];
int main(){
    // freopen("migrate.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1, j = 1;i <= n;i++){
            cin >> x[i];
            while(j < i && x[i] - x[j] > d)j++;
            pre[i] = j;
            if(j == i){
                f[i] = 0;
            }else{
                int l0 = pre[j], l1 = pre[j + 1];
                f[i] = l1 - l0;
                if(l1 != l0)f[i] += f[j];
            }
            // cerr << i << " f=" << f[i] << "\n";
        }
        for(int i = n, j = n;i >= 1;i--){
            while(j > i && x[j] - x[i] > d)j--;
            nxt[i] = j;
            if(j == i){
                g[i] = 0;
            }else{
                int r0 = nxt[j], r1 = nxt[j - 1];
                g[i] = r0 - r1;
                if(r0 != r1)g[i] += g[j];
            }
        }
        for(int i = 1;i < n;i++){
            if(nxt[pre[i]] == i)f[i] += pre[i + 1] - pre[i];
            else f[i] = pre[i + 1] - pre[i];
        }
        ll ans = 0;
        // for(int i = 1;i <= n;i++)cerr << pre[i] << " " << nxt[i] << " f=" << f[i] << " g="<< g[i] << "\n";
        for(int i = 1;i <= n;i++){
            int r = nxt[i];
            if(nxt[i - 1] >= r - 1)f[i] = 1;
            else f[i]++;
            if(r == i + 1)continue;
            // cerr << i << " " << f[i] << "\n";
            if(nxt[r] == nxt[r - 1]){
                if(nxt[r - 2] != nxt[r - 1]){
                    ans += f[i] * g[r];
                }
            }
            if(nxt[r - 1] > r){ //(r, nxt[r - 1]]
                int L = r + 1, R = nxt[r - 1];
                L = max(L, nxt[r - 2] + 1);
                if(L <= R)ans += f[i] * (R - L + 1);
            }
            // cerr << i << " ans=" << ans << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}