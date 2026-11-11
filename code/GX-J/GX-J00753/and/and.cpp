#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[10005]={},dp[10005]={};
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(m<=3){
        while(m>0){
            for(long long i=1;i<=n;i++){
                for(long long k=i+1;k<=n;k++){
                    dp[i]=max(dp[i],a[i]&a[k]);
                }
            }
            m--;
        }
        for(long long i=n;i>0;i--){
            if(dp[i]!=0){
                cout<<dp[i];
                return 0;
            }
        }
        cout<<0;
        return 0;
    }
    else{
        while(m>0){
            for(long long i=1;i<=n;i++){
                for(long long k=i+1;k<=n;k++){
                    dp[i]=max(dp[i],a[i]&a[k]);
                }
            }
            m--;
        }
        for(long long i=n;i>0;i--){
            if(dp[i]!=0){
                cout<<dp[i];
                return 0;
            }
        }
        if(n==m){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
        }
    }
}
