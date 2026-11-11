#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int cccc,n,m,ddddd;
int w[500009];
vector<pair<int,int> > xl[500009];
int dis[509][509];
signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int q;
    cin>>cccc>>n>>m>>ddddd>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,v;
            cin>>u>>v;
            xl[u].push_back({i,v});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e16;
            if(i==j){
                dis[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(auto u:xl[i]){
            for(auto v:xl[i]){
                dis[u.first][v.first]=min(u.second+v.second,dis[u.first][v.first]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans;
        ans=1e16;
        for(auto u:xl[x]){
            for(auto v:xl[y]){
                ans=min(ans,dis[u.first][v.first]+u.second+v.second+w[x]+w[y]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
