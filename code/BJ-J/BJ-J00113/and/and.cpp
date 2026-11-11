#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,num,ans;
ll a[200005];
ll dp[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m == 1){
        ll num = 0;
        for(int i = 1;i <= n;i++){
            cin>>a[i];
            num = max(num,a[i]);
        }
        cout<<num;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        dp[0] = a[i];
        for(int j = m;j >= 0;j--){
            if(j >= 1){
                ll c = dp[j-1]&a[i];
                dp[j] = max(dp[j],c);
            }
        }
    }
    cout<<dp[m];
    return 0;
}
