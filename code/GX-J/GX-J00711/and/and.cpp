#include<bits/stdc++.h>
using namespace std;
int n,m,f,x;
int a[200001],dp[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=max(x,a[i]);
    }
    dp[0]=x;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            dp[j]=max(dp[j],int(dp[j-1]&a[i]));
        }
    }
    cout<<dp[m];
    return 0;
}
