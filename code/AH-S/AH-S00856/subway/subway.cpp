#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct edge{
    int v,w;
};
int n,m,a,b,c,d,q;
int f[3*N];
struct node{
    int u;
    bool operator <(const node b)const{
        return f[u]>f[b.u];
    }
};
vector<edge> g[3*N];
int dijkstra(int st,int ed){
    memset(f,0x3f,sizeof f);
    f[st]=0;
    priority_queue<node> q;
    q.push({st});
    while(!q.empty()){
        node h=q.top();q.pop();
        int u=h.u;
//        cerr<<u<<" "<<f[u]<<"    ";
        if(u==ed)continue;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v,w=g[u][i].w;
//            cout<<w<<" ";
            if(f[u]+w<f[v]){
                f[v]=f[u]+w;
                q.push({v});
            }
        }
    }
    return f[ed];
}
main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&a,&b,&d,&q);
    n=a+2*b;
    for(int i=1,w;i<=b;i++){
        scanf("%lld",&w);
//        cerr<<w<<" ";
        int u=i,v=i+b;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1,k;i<=a;i++){
        scanf("%lld",&k);
        for(int j=1,ax,t;j<=k;j++){
            scanf("%lld%lld",&ax,&t);
            int u=ax+b,v=i+2*b,w=t;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<g[i].size();j++){
//            cerr<<g[i][j].v<<" "<<g[i][j].w<<endl;
//        }
//    }
    while(q--){
        int st,ed;
        scanf("%lld%lld",&st,&ed);
        printf("%lld\n",dijkstra(st,ed));
//        cerr<<endl;
    }
    return 0;
}
