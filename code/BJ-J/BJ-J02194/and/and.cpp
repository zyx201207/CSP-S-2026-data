#include<bits/stdc++.h>
using namespace std;
long long a[200008];
long long dp[200008];


int main(){
    int ans = 0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
   // sort(a + 1, a + n + 1, cmp);
    dp[1] = a[1] & a[2];
    int m1 = m;
    for(int i = 1; i < n; i++){

        long long s = dp[i];
        dp[i] = max(dp[i], a[i] & a[i + 1]);
        //cout << dp[i] << " ,";
        m1--;
        if(s != dp[i]){
            m1 = m - 1;
        }
        if(m1 == 0){
            cout << dp[i];
            return 0;
        }

    }
    cout << dp[n - 1];
    return 0;
}
