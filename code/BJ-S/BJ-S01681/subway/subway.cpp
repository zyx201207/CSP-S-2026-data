#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q,w[M];
vector<int> v[M],t[M];
ll e[505][505],dis[505][505];
bool vis[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int x,y; cin>>x>>y;
            v[x].push_back(i),t[x].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) e[i][j]=dis[i][j]=inf;
        e[i][i]=dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int k=v[i].size();
        for(int x=0;x<k;x++){
            int px=v[i][x],wx=t[i][x];
            for(int y=x+1;y<k;y++){
                int py=v[i][y],wy=t[i][y];
                if(wx+wy<e[px][py]) e[px][py]=wx+wy;
                if(wx+wy<e[py][px]) e[py][px]=wx+wy;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) vis[j]=0;
        dis[i][0]=inf;
        for(int j=1;j<=n;j++){
            int x=0;
            for(int y=1;y<=n;y++)
                if((!vis[y])&&dis[i][y]<dis[i][x]) x=y;
            for(int y=1;y<=n;y++)
                if(dis[i][x]+e[x][y]<dis[i][y]) dis[i][y]=dis[i][x]+e[x][y];
            vis[x]=1;
        }
    }
    while(q--){
        int x,y; cin>>x>>y;
        ll ans=inf;
        int kx=v[x].size(),ky=v[y].size();
        for(int xi=0;xi<kx;xi++){
            int px=v[x][xi],wx=t[x][xi];
            for(int yi=0;yi<ky;yi++){
                int py=v[y][yi],wy=t[y][yi];
                ll sum=dis[px][py]+wx+wy;
                if(sum<ans) ans=sum;
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}