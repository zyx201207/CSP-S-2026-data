#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[600001];
long long dis[601][601];
vector<pair<int,int> > hv[600001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(dis,127,sizeof(dis));
    for(int i=1;i<=n;i++){
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            hv[a].push_back({i,t});
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<hv[i].size();j++){
            for(int l=j+1;l<hv[i].size();l++){
                int x=hv[i][j].first,y=hv[i][l].first;
                long long w=hv[i][j].second+hv[i][l].second;
                dis[x][y]=min(dis[x][y],w);
                dis[y][x]=min(dis[y][x],w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]>=(1ll<<60)||dis[k][j]>=(1ll<<60)){
                    continue;
                }
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=(1ll<<60);
        for(auto v1:hv[x]){
            for(auto v2:hv[y]){
                ans=min(ans,dis[v1.first][v2.first]+v1.second+v2.second);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
}
