#include<bits/stdc++.h>
#define ll long long
using namespace std;//00.04 yu 2.26
struct no{
int v,w;
};
int c,n,m,d,q,zk[510000];
vector<no> gx[2100],gz[510000];
ll dp[510000],yg[510000];
int dfs(int x,int w){
    ll minn=0x3f3f3f3f,bh=-1;
    for(int i=0;i<gz[x].size();i++){
        for(int j=0;j<gx[gz[x][i].v].size();j++){
            if(yg[gx[gz[x][i].v][j].v]==0&&dp[gx[gz[x][i].v][j].v]>w+gz[x][i].w+gx[gz[x][i].v][j].w){
                dp[gx[gz[x][i].v][j].v]=w+gz[x][i].w+gx[gz[x][i].v][j].w;
            }
        }
    }
}
int slove(int x){
    for(int i=1;i<=m;i++){
        int minn=0x3f3f3f,bh=-1;
        for(int j=1;j<=m;j++){

            if(!yg[j]&&dp[j]<minn){
                minn=dp[j],bh=j;
            }
        }
      //  cout<<bh<<" "<<dp[bh]<<endl;
        yg[bh]=1;

        dfs(bh,dp[bh]);
    }
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>zk[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            gx[i].push_back({x,y});
            gz[x].push_back({i,y});
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        memset(dp,0x3f,sizeof(dp));
        memset(yg,0,sizeof(yg));
        dp[x]=zk[x];

        slove(x);
        /*
        cout<<endl<<endl<<endl;
        cout<<x<<" "<<y<<endl;
        for(int i=1;i<=m;i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        */
        cout<<dp[y]+zk[y]<<endl;
    }
    return 0;
}

