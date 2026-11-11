#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dp[200005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    scanf("%d",&a[1]);
    ans = a[1];
    for(int i = 2;i <= n;i++){
        scanf("%d",&a[i]);
        ans = ans & a[i];
    }
    if(m == n){
        cout << ans;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        dp[0] = a[i];
        for(int j = i;j >= 1;j--){
            dp[j-1] = dp[j-1];
            dp[j] = max(dp[j],dp[j-1] & a[i]);
        }
    }
    cout << dp[m];
    return 0;
}
