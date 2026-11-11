#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,vv,t,LEN,ans,now;
int a[500005],dis[505][505];
vector<pair<int,int>>g[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)dis[i][j]=LONG_MAX/2;
            }
    }
    for(int i=1;i<=n;i++){
        cin>>LEN;
        for(int j=1;j<=LEN;j++){
            cin>>vv>>t;
            g[vv].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto u:g[i]){
            for(auto v:g[i]){
                if(u.first!=v.first) dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=dis[i][j];
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=LONG_MAX/2;
        for(auto u:g[x]){
            for(auto v:g[y]){
                ans=min(ans,dis[u.first][v.first]+u.second+v.second);
            }
        }
        cout<<ans+a[x]+a[y]<<"\n";
    }
    return 0;
}
