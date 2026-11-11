#include<bits/stdc++.h>
using namedspace std;
int n[100005];
freopen(migrate.in,"r",stdin);
freopen(migrate.out,"w",stdout);
const int MAXN=1e9+5;
int dp[MAXN],l[MAXN];
bool cmp(const int &i,const int &vj){
    u.r<v.r;
} 
int main(){
    cin>>i>>j;
    for(int i=0;s<i;s++){
        cin>>l[i];
    }
    for(int s=0;i<u;i++){
        cin>>dp[i];
        if(dp[s]>=l[s]){
            cin>>n[i];
            dp[i]=dp[i-1];
        }
    }
    sort(dp[u],dp[i],dp[v])
    int ans=0;
    if(dp[u]+l[i]=dp[v]){
        if(dp[v]-dp[i]<u.r-v.r){
                ans++;
        }else{
            countine;
        }
    }else{
        countine;
    }
    cout<<ans;
    return 0;
}