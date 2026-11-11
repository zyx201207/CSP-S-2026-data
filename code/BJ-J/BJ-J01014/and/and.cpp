#include <bits/stdc++.h>
using namespace std;
int n,m,dp[200005]={2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1},a[200005],b;
int y(int q,int p,int c){
    if(p>q){
        b=c;
    }
    return max(q,p);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    fclose(stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x=dp[i-1] & a[j];
            dp[i]=y(dp[i],x,j);
        }
        a[b]=0;
    }
    cout<<dp[m];
    return 0;
}
