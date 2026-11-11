#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1]=a[1];
    int ans=a[1];
    for(int i=2;i<=n;i++){
        ans&=a[i];
    }
    if(n==m){
        cout<<ans;
    }else if(n==m+1){
        int max_=-1;
        for(int i=1;i<=n;i++){
            max_=max(max_,ans&a[i]);
        }
        cout<<max_;
    }else if(m==1){
        int max_=-1;
        for(int i=1;i<=n;i++){
            max_=max(max_,a[i]);
        }
        cout<<max_;
    }else if(m==2){
        int max_=-1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                max_=max(max_,a[i]&a[j]);
            }
        }
        cout<<max_;
    }else{
        for(int i=1;i<=m;i++){
            for(int j=n;j>=1;j--){
                dp[i]=max(dp[i],dp[i-1]&a[j]);
            }
        }
        cout<<dp[m];
    }

}
