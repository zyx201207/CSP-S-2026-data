#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,n,m,d,q;
int tmp[500005];
vector<int>v[500005],w[500005];
ll dis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>tmp[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int a,t;cin>>a>>t;
            v[a].push_back(i);w[a].push_back(t);
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1e18;
    for(int i=1;i<=m;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=j+1;k<v[i].size();k++){
                dis[v[i][k]][v[i][j]]=dis[v[i][j]][v[i][k]]=min(dis[v[i][j]][v[i][k]],(ll)w[i][j]+w[i][k]);
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
        int x,y;cin>>x>>y;
        ll ans=1e18;
        for(int i=0;i<v[x].size();i++){
            for(int j=0;j<v[y].size();j++){
                ans=min(ans,dis[v[x][i]][v[y][j]]+w[x][i]+w[y][j]);
            }
        }
        ans+=tmp[x]+tmp[y];
        cout<<ans<<'\n';
    }
    return 0;
}
