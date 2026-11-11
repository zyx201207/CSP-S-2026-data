#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int M=3e4+5;
const ll inf=1e16;
int c,n,m,d,Q;
ll w[M],dis[M],que[M];
struct Node{
    int u;ll dis;
    bool operator <(Node x)const{
        return dis>x.dis;
    }
};
struct Edge{
    int v;ll w;
};
priority_queue<Node> q;
vector<Edge> sz[M];
ll Dijk(int s,int e){
    for(int i=1;i<=m+n;i++) dis[i]=inf,que[i]=0;
    dis[s]=0;q.push({s,0});
    while(!q.empty()){
        int now=q.top().u;q.pop();
        if(que[now]) continue;
        que[now]=1;
        for(auto i:sz[now]){
            if(dis[i.v]>dis[now]+i.w){
                dis[i.v]=dis[now]+i.w;
                q.push({i.v,dis[i.v]});
            }
        }
    }
    return dis[e];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a;ll t;
            scanf("%d%lld",&a,&t);
            sz[m+i].push_back({a,t});
            sz[a].push_back({m+i,t});
        }
    }
    for(int i=1;i<=Q;i++){
        int s,e;
        scanf("%d%d",&s,&e);
        ll res=w[s]+w[e]+Dijk(s,e);
        printf("%lld\n",res);
    }
    return 0;
}
