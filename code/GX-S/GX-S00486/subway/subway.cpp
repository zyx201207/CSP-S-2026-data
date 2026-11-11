#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,dp[10005][10005],t[10005][10005],k[10005],w[10005],xx,yy,sum=1000000000;
void dfs(int x,int y,int ttime){
    if(dp[x][1]==0)
    return;
    if(x==y){
        sum=min(ttime,sum);
        return;
    }
    for(int i=1;i<=k[x];i++){
        dfs(dp[x][i],y,ttime+t[x][i]);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        for(int j=1;j<=l;j++){
        int x,y;
        cin>>x>>y;
        if(j!=1){
            k[xx]++;
            dp[xx][k[xx]]=x;
            t[xx][k[xx]]=y;
        }
        xx=x;yy=y;
        }
    }int x=1;
    for(int i=1;i<=q;i++){
        int b,s;
        cin>>b>>s;
        dfs(b,s,0);
    cout<<sum<<"\n";//+w[b]+w[s]
    }
    return 0;
}
