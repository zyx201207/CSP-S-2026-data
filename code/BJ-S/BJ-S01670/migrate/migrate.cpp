#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n;
ll d,x[2000007],cnt[2000007];
int one[2000007];
ll ans = 0;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while(T--){
        ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
            cnt[i] = 0;
            one[i] = 0;
        }
        one[n + 1] = 0;
        for(int i = n;i >= 1;i--){
            int tg = lower_bound(x + 1,x + n + 1,x[i] - d) - x;
            if(tg == i)continue;
            if(upper_bound(x + 1,x + n + 1,x[tg] + d) - x > i + 1)continue;
            cnt[tg] += cnt[i];
            ans += cnt[i];
            if(tg == i - 1){
                one[i - 1] = one[i] + 1;
                continue;
            }
            int r = upper_bound(x + 1,x + n + 1,x[i] + d) - x;
            int m = upper_bound(x + 1,x + n + 1,x[i - 1] + d) - x;
            int l = upper_bound(x + 1,x + n + 1,x[i - 2] + d) - x;
            if(r == i)continue;
            if(r == m && m == l)continue;
            cnt[tg] += (m - l) * (one[r - 1] + 1);
            //cout << i << (m - l) * (one[r - 1] + 1) + cnt[i] << " ";
            ans += (m - l) * (one[r - 1] + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}