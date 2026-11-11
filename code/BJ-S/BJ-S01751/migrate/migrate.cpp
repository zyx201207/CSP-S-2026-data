#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000005],l[2000005],r[2000005],f[2000005],g[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        for(int i = 1;i <= n;i++){
            r[i] = r[i - 1];
            while(r[i] < n && x[r[i] + 1] - x[i] <= d){
                r[i]++;
            }
        }
        l[n + 1] = n;
        for(int i = n;i > 0;i--){
            l[i] = l[i + 1];
            while(l[i] > 1 && x[i] - x[l[i] - 1] <= d){
                l[i]--;
            }
        }
        for(int i = 1;i <= n;i++){
            f[i] = g[i] = 1;
//            cout << l[i] << " " << r[i] << '\n';
        }
        for(int i = 1;i <= n;i++){
            if(r[i] == i){
                continue;
            }
            if(l[r[i]] == i){
                f[r[i]] += f[i];
            }else{
                f[r[i]]++;
            }
        }
        for(int i = n;i > 0;i--){
            if(l[i] == i){
                continue;
            }
            if(r[l[i]] == i){
                g[l[i]] += g[i];
            }else{
                g[l[i]]++;
            }
        }
        long long ans = 0;
        for(int i = 2;i < n - 1;i++){
            if(r[i] <= i + 1 || l[i + 1] >= i){
                continue;
            }
            int cnt1 = l[i + 2] - l[i + 1],cnt2 = r[i] - r[i - 1];
            if(r[l[i]] == i + 1){
                cnt1 += f[l[i]] - 1;
            }
            if(l[r[i + 1]] == i){
                cnt2 += g[r[i + 1]] - 1;
            }
//            cout << cnt1 << " " << cnt2 << '\n';
            ans += 1ll * cnt1 * cnt2;
        }
        cout << ans << '\n';
    }
    return 0;
}
