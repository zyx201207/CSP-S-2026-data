#include<bits/stdc++.h>
using namespace std;
const int MAXLEN=5e5+5;
int c,n,m,d,Q,wsss[500005]={0},cnt=0,cc;
struct node{
    int id;
    long long w;
};
node ggg[500005][21];
int cnts[MAXLEN]={0};
long long dp[505][505];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //memset(cnts,0,sizeof(cnts));
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>wsss[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=5e14;
        }
    }
    int T;
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
                cin>>a>>t;
                ggg[a][++cnts[a]]=(node){i,t};
                for(int o=1;o<cnts[a];o++){
                    dp[i][ggg[a][o].id]=min(dp[i][ggg[a][o].id],ggg[a][o].w+t);
                    dp[ggg[a][o].id][i]=min(dp[i][ggg[a][o].id],ggg[a][o].w+t);
                }
            }
        }/*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%lld ",dp[i][j]);
            }
            printf("\n");
        }*/
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        while(Q--){
            int x,y;
            cin>>x>>y;
            long long ans=LONG_LONG_MAX;
            for(int i=1;i<=cnts[x];i++){
                for(int j=1;j<=cnts[y];j++){
                    ans=min(ans,dp[ggg[x][i].id][ggg[y][j].id]+ggg[x][i].w+ggg[y][j].w+wsss[x]+wsss[y]);
                }
            }
            cout<<ans<<'\n';
        }
        return 0;
}
