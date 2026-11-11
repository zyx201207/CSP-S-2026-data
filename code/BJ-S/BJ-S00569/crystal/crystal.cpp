#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll dp[500005];
ll cf[500005];
ll dp2[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dp[2]=1e24;
    for(int i=1;i<n;i++){
            cf[i]=1e24;
        cf[i]=a[i+1]-a[i];
        dp[2]=min(dp[2],cf[i]);
    }
    for(int i=3;i<=n;i++){
        int ans=0;
        for(int j=0;j<i-1;j++){
            for(int k=i-1;k>=1+j;k--){
                ans+=cf[k];
            }
        }
        dp[i]=ans;
    }
    int ans=0,pos=-1;
    for(int i=2;i<=n;i++){
        if(dp[i]<=m){
            if(dp[i]>=ans){
                ans=dp[i];
                pos=i;
            }
        }
    }
    cout<<pos;
    return 0;
}
