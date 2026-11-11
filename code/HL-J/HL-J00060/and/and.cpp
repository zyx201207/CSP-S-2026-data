#include<bits/stdc++.h>
using namespace std;
long long dp[100005];
long long a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=0;i<=n;i++){
        dp[i] = (1<<60)-1;
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i] = max(dp[i],dp[i-1]^a[i]);
        }
    }
    cout << dp[n];
    return 0;
}
