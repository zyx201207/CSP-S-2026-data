#include<bits/stdc++.h>
using namespace std;
int an(int x,int y){
    int ans=0;
    for(int i=31;i>=0;i--){
        long long i1=pow(2,i);
        if(x>=i1){
            x-=i1;
            if(y>=i1){
                ans+=i1;
            }
        }
        if(y>i1){
            y-=i1;
        }
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200010],maxa,maxi;
    int dp[200010];
    memset(dp,0,sizeof dp);
    bool vis[200010];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxa){
            maxa=a[i];
            maxi=i;
        }
    }
    dp[1]=maxa;
    vis[maxi]=1;
    dp[0]=0;
    for(int j=n;j>=1;j--){
        for(int i=2;i<=m;i++){
            if(!vis[j]){
                int a1=an(dp[i-1],a[i]);
                if(a1>dp[i]){
                    maxi=j;
                }
                dp[i]=max(dp[i],a1);
            }
        }
        vis[maxi]=1;
    }
    cout<<dp[m];
}
