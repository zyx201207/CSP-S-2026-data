#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long dp[200005]={0};
    long long a[200005];
    long long ma=0;
    long long as=LONG_LONG_MAX;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        as&=a[i];
    }
    if(m==n){
        cout<<as;
        return 0;
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==2){
        long long anan=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                anan=max(anan,a[i]&a[j]);
            }
        }
        cout<<anan;
        return 0;
    }
    dp[0]=LONG_LONG_MAX;
    for(long long j=1;j<=n;j++){
        for(long long i=min(m,j);i>=1;i--){
            dp[i]=max(dp[i-1]&a[j],dp[i]);
            //cout<<dp[i]<<' ';
        }
        //cout<<'\n';
    }
    cout<<dp[m];
    return 0;
}