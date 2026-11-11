//GZ-J00245
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[n + 5];
    vector<int> dp(m + 1,0);
    cin>>a[1];dp[1] = a[1];
    for(int i = 2;i <= n;i++){
        cin>>a[i];
        for(int j = m;j >= 1;j--){
            dp[j] = max(dp[j],dp[j - 1] & a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
