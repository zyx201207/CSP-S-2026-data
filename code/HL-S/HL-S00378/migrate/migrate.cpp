#include<bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005], ans, dp[2000006];
bool mig(int k){
    dp[k] = 0;
    long long l = 0x7ffffffffffffff, c;
    for(int i = k - 1; i >= 0; i--){
        if(a[k] - a[i] < d + 2){
            if(l > dp[i]){
                l = dp[i];
                c = 1;
            }
            else  if(l == dp[i])
                c++;
        }
    }
    dp[k] = l + 1;
    cout << c;
    return c == 2 && dp[k] != 0x8000000000000000;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 1; i < n; i++){
            if(mig(i))
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
