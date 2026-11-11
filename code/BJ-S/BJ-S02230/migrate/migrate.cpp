#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e6 + 9;
bool st;
int id, n; ll d, ans;
int pos[N];
ll dp[N], a[N], siz[N], f[N], g[N];
bool ed;
double Time(){
    return (double)clock()/CLOCKS_PER_SEC;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t; cin >> id >> t;
    while(t--){
        scanf("%d %lld", &n, &d);
        for(int i=1; i<=n; ++i){
            scanf("%lld", &a[i]);
            int l = 1, r = i, res = i;
            while(l<=r){
                int mid = l + r >> 1;
                if(a[i]-a[mid]<=d) r = mid - 1, res = mid;
                else l = mid + 1;
            }pos[i] = res;
            if(res^i) ++dp[res];
            else pos[i] = 0;
            // cout << "pos " << i << " = "<<pos[i]<<endl;
        }
        for(int i=n; i; --i){
            if(pos[i]^pos[i+1]){
                dp[pos[i]] += dp[i];
            }
        }
        
        for(int i=1; i<=n; ++i){
            int l = i, r = n, res = i;
            while(l<=r){
                int mid = l + r >> 1;
                if(a[mid]-a[i]<=d) l = mid + 1, res = mid;
                else r = mid-1;
            }g[i] = res;
            if(res^i) ++f[res];
            else g[i] = 0;
            // cout << "g " << i << " = "<<g[i]<<endl;
        }
        for(int i=1; i<=n; ++i){
            // cout << "dp "<<i<<" = "<<dp[i]<<endl;
            if(g[i]^g[i-1]){
                f[g[i]] += f[i];
            }
        }

        for(int i=1; i<=n; ++i){
            // cout << "f "<<i<< " = "<<f[i]<<endl;
            int l = i, r = n, res = i;
            while(l<=r){
                int mid = l + r >> 1;
                if(a[mid]-a[i]<=d) l = mid + 1, res = mid;
                else r = mid - 1;
            }siz[i] = res - i;
        }
        for(int i=1; i<=n; ++i){
            // cout << "siz "<<i<<" = "<<siz[i]<<endl;
            // if(siz[i]^2) continue;
            if(siz[i]<2) continue;
            ll pre = 0, nxt = 0;

            if(g[i+siz[i]]>g[i+siz[i]-1]) nxt = g[i+siz[i]-1] - g[i+siz[i]-2];
            else nxt = dp[i+siz[i]-1];

            if(pos[i+siz[i]-1]<i) pre = 1;
            else pre = f[i] + 1;

            // cout << "i = "<<i<<" ans += "<<pre * nxt <<endl;
            // cout << "pre = "<<pre<< ' ' << "nxt = "<<nxt<<endl;

            ans += pre * nxt;

            // ans += (f[i]+1) * dp[i+siz[i]-1];
        }
        printf("%lld\n", ans); ans = 0;
        for(int i=0; i<=n; ++i)
        siz[i] = pos[i] = dp[i] = a[i] = f[i] = g[i] = 0;
    }
    // cerr << Time() << 's' << endl;
    // cerr << (&st-&ed)/1024.0/1024<<endl;
}