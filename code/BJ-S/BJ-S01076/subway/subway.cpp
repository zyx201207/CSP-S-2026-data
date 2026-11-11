#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=505,M=5e5+5,inf=998244353299792458;
int c,n,m,d,q,w[M],dis[N][N];
vector<pii> f[M];
// sta wal
void floyd(){
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=inf;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++)f[i].pb({0,0});
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int x=1,k;x<=n;x++){
        cin>>k;
        for(int p=1,aa,tt;p<=k;p++){
            cin>>aa>>tt;
            f[aa].pb({x,tt});

        }
    }
    for(int x=1;x<=m;x++){
        int sz=f[x].size();
        if(sz>=2){
            for(int i=1;i<sz-1;i++){
                for(int j=i+1;j<sz;j++){
dis[f[x][i].fi][f[x][j].fi]=min(dis[f[x][i].fi][f[x][j].fi],f[x][i].se+f[x][j].se);
dis[f[x][j].fi][f[x][i].fi]=dis[f[x][i].fi][f[x][j].fi];
                }
            }
        }
    }
    floyd();
    for(int ttt=1,x,y;ttt<=q;ttt++){
        cin>>x>>y;
        int siz1=f[x].size(),siz2=f[y].size(),ans=inf;
        for(int i=1;i<siz1;i++){
            for(int j=1;j<siz2;j++){
                ans=min(ans,dis[f[x][i].fi][f[y][j].fi]+f[x][i].se+f[y][j].se);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
//30min pass
