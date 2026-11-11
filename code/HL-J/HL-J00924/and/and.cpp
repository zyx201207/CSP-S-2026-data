#include<bits/stdc++.h>
using namespace std;
int n,r,a[200005],mx;
struct{
    int mx;
    int t;
}dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>r;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        dp[i].mx = -1;
        for(int j = 1;j<i;j++){
            if(dp[i].t < r){
                dp[i].mx = max(dp[i].mx,dp[j].mx & a[i]);
                mx = max(mx,j);
                dp[i].t = dp[mx].t + 1;

            }
        }
    }
    cout<<dp[n].mx;
    return 0;
}
