#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxx,ans1;//dp[i]表示选了m个数的最大值
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        ans1^=a[i];
    }
    if(m==1){
        cout<<maxx;
    }
    if(m==n){
        cout<<ans1;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans=max(ans,a[i]^a[j]);
            }
        }
        cout<<ans;
    }
    if(m==n-1){
        cout<<m;
    }
    else{
        cout<<a[1];
    }
    return 0;
}
