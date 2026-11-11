/*
题面保证任意两点均可达，而样例中每一条线路都是编号递增的，于是可以推断地铁是双向的。
*/
#include<bits/stdc++.h>
using namespace std;
namespace Mortis{
using ll=long long;
constexpr ll inf=0x3f3f3f3f3f3f3f3f;
ll dis[501][501];
int w[500001];
vector<pair<int,int>>edge[500001];
void main(){
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)fill(dis[i]+1,dis[i]+n+1,inf),dis[i][i]=0;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int a,t;k--;)cin>>a>>t,edge[a].emplace_back(i,t);
    }
    for(int i=1;i<=m;++i)
        for(const auto&[u,tu]:edge[i])
            for(const auto&[v,tv]:edge[i])
                dis[u][v]=min(dis[u][v],ll(tu+tv));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    for(int s,t;q--;){
        cin>>s>>t;
        ll res=inf;
        for(const auto&[u,tu]:edge[s])
            for(const auto&[v,tv]:edge[t])
                res=min(res,dis[u][v]+tu+tv);
        cout<<res+w[s]+w[t]<<'\n';
    }
}
}
int main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    Mortis::main();
    return 0;
}