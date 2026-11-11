#include<bits/stdc++.h>
#define int long long
using namespace std;
int inf=0x3f3f3f3f3f3f3f3f;
struct pr{
    int x,t;
};
struct node{
    int n;
    pr o[25];
}a[500005];
int db;
int c,m,n,d,q,bs[500005],dp[505][505];
//m:xian lu  n:zhan dian  d:degree q:qes
//dp: i xian huancheng j xian
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    db=0;
    if(db==0){
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
    }
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>bs[i];//ji de jia shang
    for(int i=1;i<=m;i++){
        int l;
        cin>>l;
        for(int j=1;j<=l;j++){
            int x,t;
            cin>>x>>t;
            a[x].o[++a[x].n]={i,t};
        }
    }
    memset(dp,inf,sizeof dp);
    for(int i=1;i<=m;i++)dp[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].n;j++){
            for(int k=j+1;k<=a[i].n;k++){//mistake
                pr oj=a[i].o[j],ok=a[i].o[k];
                dp[oj.x][ok.x]=dp[ok.x][oj.x]=min(dp[oj.x][ok.x],oj.t+ok.t);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int u,v,ans=inf;
        cin>>u>>v;
        for(int i=1;i<=a[u].n;i++){
            for(int j=1;j<=a[v].n;j++){
                pr uu=a[u].o[i],vv=a[v].o[j];
                ans=min(ans,bs[u]+bs[v]+uu.t+vv.t+dp[uu.x][vv.x]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}