#include<bits/stdc++.h>
using namespace std;
const int N=500,M=500000;
const long long Inf=1000000000000;
struct RP{
    struct point{
        int v;
        long long w;
    };
    vector<point>edge;
}b[M+5];
long long dis[N+5][N+5];
int testid,n,m,d,q,a[M+5];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>testid>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=Inf;
    for(int i=1;i<=n;++i)dis[i][i]=0;
    for(int i=1;i<=m;++i)cin>>a[i];
    for(int i=1,k;i<=n;++i){
        cin>>k;
        for(int j=1,v,w;j<=k;++j){
            cin>>v>>w;
            b[v+n].edge.push_back({i,w});
        }
    }
    for(int i=1;i<=m;++i){
        int now=i+n;
        for(int j=0;j<(int)b[now].edge.size();++j){
            for(int k=j+1;k<(int)b[now].edge.size();++k){
                dis[b[now].edge[j].v][b[now].edge[k].v]=dis[b[now].edge[k].v][b[now].edge[j].v]=min(dis[b[now].edge[j].v][b[now].edge[k].v],b[now].edge[j].w+b[now].edge[k].w);
            }
        }
    }
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1,u,v;i<=q;++i){
        cin>>u>>v;
        int U=u+n,V=v+n;
        long long sum=Inf;
        for(int j=0;j<(int)b[U].edge.size();++j){
            for(int k=0;k<(int)b[V].edge.size();++k){
                sum=min(sum,dis[b[U].edge[j].v][b[V].edge[k].v]+b[U].edge[j].w+b[V].edge[k].w);
            }
        }
        cout<<sum+a[u]+a[v]<<'\n';
    }
    return 0;
}
