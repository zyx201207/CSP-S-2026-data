#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,a[N],k[N],dis[550][550];vector<pair<int,int>>g[N];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x,y;j<=k[i];j++)
            cin>>x>>y,g[x].push_back({y,i});
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            dis[i][j]=dis[j][i]=1e18;
    for(int i=1;i<=m;i++)
        for(pair<int,int>j:g[i])
            for(pair<int,int>k:g[i])
                if(k!=j){
                    auto[v1,id1]=j;auto[v2,id2]=k;
                    dis[id1][id2]=min(dis[id1][id2],v1+v2);dis[id2][id1]=dis[id1][id2];
                }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;cin>>x>>y;
        int res=1e18;
        for(pair<int,int>v:g[y])
            for(pair<int,int>v2:g[x])
                res=min(res,dis[v.second][v2.second]+v.first+v2.first);
        cout<<res+a[x]+a[y]<<'\n';
    }
    return 0;
}
