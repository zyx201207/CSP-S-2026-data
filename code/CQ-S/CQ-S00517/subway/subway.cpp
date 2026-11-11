#include<bits/stdc++.h>
#define int long long
#define il inline
#define co const
#define re register
using namespace std;
il int read();
co int N=510;
co int M=5e5+10;
int dis[N][N],w[M],cnt[M];
pair<int,int> g[M][30];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int bh=read(),n=read(),m=read(),d=read(),q=read();
    for(re int i=1;i<=m;++i){
        w[i]=read();
    }
    for(re int i=1;i<=n;++i){
        int gs=read();
        for(re int j=1;j<=gs;++j){
            co int x=read();
            g[x][++cnt[x]]={i,read()};
        }
    }
    for(re int i=1;i<=n;++i){
        for(re int j=1;j<i;++j){
            dis[j][i]=dis[i][j]=1e18;
        }
    }
    for(re int ib=1;ib<=m;++ib){
        int si=cnt[ib];
        for(re int i=1;i<=si;++i){
            co int x=g[ib][i].first,z=g[ib][i].second;
            for(re int j=1;j<i;++j){
                co int y=g[ib][j].first;
                dis[y][x]=dis[x][y]=min(dis[x][y],z+g[ib][j].second);
            }
        }
    }
    for(re int i=1;i<=n;++i){
        for(re int j=1;j<=n;++j){
            for(re int k=1;k<=n;++k){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int i=read(),j=read();
        // cout<<i<<' '<<j<<'s';
        int minn=1e18;
        for(re int ii=1;ii<=cnt[i];++ii){
            co int x=g[i][ii].first,z=g[i][ii].second;
            for(re int jj=1;jj<=cnt[j];++jj){
                co int y=g[j][jj].first;
                // cout<<x<<' '<<y<<' ';
                minn=min(minn,z+g[j][jj].second+dis[x][y]);
            }
        }
        cout<<minn+w[i]+w[j]<<'\n';
    }
    return 0;
}
il int read(){
    int ans=0;
    bool op=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')op=1;
        ch=getchar();
    }
    while(isdigit(ch)){
        ans=(ans<<1)+(ans<<3)+(ch^48);
        ch=getchar();
    }
    if(op)return -ans;
    return ans;
}
