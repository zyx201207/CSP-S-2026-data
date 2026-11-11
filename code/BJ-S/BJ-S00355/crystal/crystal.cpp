#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
unsigned long long dp[500005];
unsigned long long ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(m == 0){
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            int cnt = 0;
            for(int j = i; j <= n; j ++)
                if(a[j] == a[i]) cnt ++;
                else break;
            ans = max(ans, cnt);
            i += cnt - 1;
        }
        cout << ans;
        return 0;
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i ++){
        dp[i] = dp[i - 1] + (i - 1) * (a[i] - a[i - 1]);
        if(dp[i] > m){
            ans = i - 1;
            break;
        }
}
    cout << ans;
    return 0;
}
