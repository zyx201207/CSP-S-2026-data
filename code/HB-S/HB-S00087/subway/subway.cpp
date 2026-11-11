#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=5e5+500,M=600;
LL c,n,m,d,q,tt[N],f[M][M];
vector<pair<int,LL>>pt[N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    swap(n,m);
    memset(f,0x3f,sizeof f);
    for(int x=1;x<=n;x++){
        cin>>tt[x];
    }
    for(int x=1;x<=m;x++){
        int len;
        cin>>len;
        f[x][x]=0;
        while(len--){
            LL u,w;
            cin>>u>>w;
            pt[u].push_back({x,w});
        }
    }
    for(int x=1;x<=n;x++){
        for(int i=0;i<pt[x].size();i++){
            for(int j=i+1;j<pt[x].size();j++){
                int u=pt[x][i].first,v=pt[x][j].first;
                LL w=pt[x][i].second+pt[x][j].second;
                f[u][v]=min(f[u][v],w);
                f[v][u]=min(f[v][u],w);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int x=1;x<=m;x++){
            for(int y=1;y<=m;y++){
                f[x][y]=min(f[x][y],f[x][k]+f[k][y]);
            }
        }
    }
    while(q--){
        int st,ed;
        LL ans=1e18;
        cin>>st>>ed;
        for(int i=0;i<pt[st].size();i++){
            for(int j=0;j<pt[ed].size();j++){
                ans=min(ans,pt[st][i].second+pt[ed][j].second+f[pt[st][i].first][pt[ed][j].first]);
            }
        }
        cout<<ans+tt[st]+tt[ed]<<"\n";
    }
    return 0;
}