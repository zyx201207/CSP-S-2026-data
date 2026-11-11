
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 200005
ll n,tiji,dp[maxn],a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> tiji;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    for(int i=1;i<=n;i++){
        for(int j=tiji;j>=1;j--){
            dp[j] = max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout << dp[tiji];
    return 0;
}
