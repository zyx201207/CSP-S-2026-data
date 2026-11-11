#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],pre[M],dp[N],nxt[N],now[M];//dp[i表示以i开头的一段的方案
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(nxt,0,sizeof(nxt));
    for(int i=n;i>=0;i--){
        if(pre[a[i]]==0){
            pre[a[i]]=i;
        }
        nxt[now[a[i]]]=i;
        now[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[nxt[i]]+1;
        if(i>=1&&pre[a[i-1]]==i-1){
            dp[i]+=dp[i-1];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<dp[pre[i]]<<" ";
    }
    return 0;
}
