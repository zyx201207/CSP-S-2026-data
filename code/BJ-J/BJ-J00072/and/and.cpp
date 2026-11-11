#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int v[200005];
int n,m;
void solve1(){
    int maxx=0;
    for(int i=0;i<n;i++){
        maxx=max(maxx,v[i]);
    }
    cout<<maxx;
}
void solve2(){
    dp[0][m-1]=v[1];
    for(int i=1;i<=n+1;i++){
        for(int j=m-1;j>=0;j--){
            dp[i][j]=max(dp[i-1][j+1]&v[i],dp[i-1][j]);
            cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
        }
    }
    //test
    cout<<"\n"<<dp[n][0];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    if(m==1) solve1();
    else solve2();
    return 0;
}