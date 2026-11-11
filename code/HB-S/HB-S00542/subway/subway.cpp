#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],dis[505][505];
vector<pair<int,int>> e[505],re[500005];
template<typename T> inline int mink(T x,T y){return (x<y)?x:y;}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int y,z;
            cin>>y>>z;
            e[i].push_back({y,z});
            re[y].push_back({i,z});
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=((i==j)?0:1e17);
    for(int i=1;i<=n;i++){
        for(auto j:e[i]){
            for(auto k:re[j.first])dis[i][k.first]=mink(dis[i][k.first],j.second+k.second),
            dis[k.first][i]=mink(dis[k.first][i],j.second+k.second); 
        }
    } 
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=mink(dis[i][k]+dis[k][j],dis[i][j]);
    for(int i=1;i<=q;i++){
        int x,y,ans=LLONG_MAX;
        cin>>x>>y;
        for(auto j:re[x])for(auto k:re[y])ans=mink(ans,dis[j.first][k.first]+j.second+k.second+w[x]+w[y]);
        cout<<ans<<endl;
    }
    return 0;
}