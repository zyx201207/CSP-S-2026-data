#include<bits/stdc++.h>
using namespace std;
#define fs first
#define se second
typedef pair<long long, long long> pii;
typedef long long ll;
ll x[2000010];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n;
        ll d;
        cin >> n >> d;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        x[0] = -1e18- 1000;
        x[n+1] = 1e18 + 1000;
        for(int i = 1; i <= n; i++){
            int p = upper_bound(x+1,x+2+n, x[i] + d) - x;
            p--;
            if(p-1 <= i) continue;
            int r = upper_bound(x+1,x+2+n, x[p-1] + d) - x-1;

            int q = i+1;
            if(x[i+2] - x[i] > d) continue;
            int l = upper_bound(x+1,x+2+n, x[q] + d) - x-1;
            int l1 = p+1;
            l=max(l,l1);
            
            int l2 = upper_bound(x+1, x+2+n, x[p-2]+d)-x;
            l=max(l,l2);
            if(r<l) continue;
            ans += r-l+1;
        }
        cout << ans << endl;
    }
    return 0;
}