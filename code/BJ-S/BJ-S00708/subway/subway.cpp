#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll read(){
    ll igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c<='9' and c>='0'){
        igt=(igt<<3)+(igt<<1)+c-'0';
        c=getchar();
    }
    return igt*sgn;
}

const ll maxn=int(505);
const ll maxm=int(5e5+5);//rem to fill

ll dis[maxn][maxn];

struct node{
    ll dis,u;
};

struct edge{
    ll v,w;
};

struct mycmp{
    bool operator()(const node&a,const node&b){
        return a.dis>b.dis;
    }
};

vector <edge> graph[maxn+maxm];
vector <edge> graph2[maxn];

ll inner_cost1[maxm];
ll cost1[maxn][maxn];
bool vis[maxn][maxn];

priority_queue <node,vector<node>,mycmp> bfs;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    //space cost1:cout<<sizeof(cost1)*1.0/1024.0/512.0<<"MB";
    ll c=read(),n=read(),m=read();
    ll d=read(),q=read();
    for(ll i=1;i<=m;i++){
        inner_cost1[i]=read();
    }
    for(ll i=1;i<=n;i++){
        ll k=read();
        ll a,t;
        while(k--){
            a=read(),t=read();
            graph[i].push_back({n+a,t});
            graph[n+a].push_back({i,t});
        }
    }

    //before solve
    //i have to prepare;

    for(ll i=n+1;i<=n+m;i++){
        if(ll(graph[i].size())<2)continue;
        for(ll j=0;j<ll(graph[i].size());j++){
            for(ll k=j+1;k<ll(graph[i].size());k++){
                dis[graph[i][j].v][graph[i][k].v]=max(graph[i][j].w+graph[i][k].w,dis[graph[i][j].v][graph[i][k].v]);
                dis[graph[i][k].v][graph[i][j].v]=max(graph[i][k].w+graph[i][j].w,dis[graph[i][k].v][graph[i][j].v]);
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(dis[i][j]){
                graph2[i].push_back({j,dis[i][j]});
            }
        }
    }
    /*
    for(ll i=1;i<=n;i++){
        for(const edge &s:graph2[i]){
            printf("v%lldw%lld ",s.v,s.w);
        }
        printf("\n");
    }
    */
    memset(cost1,0x3f,sizeof(cost1));
    for(ll i=1;i<=n;i++){
        cost1[i][i]=0;
        bfs.push({0LL,i});
        while(!bfs.empty()){
            node tmp=bfs.top();
            bfs.pop();
            if(vis[i][tmp.u])continue;
            vis[i][tmp.u]=1;
            for(const edge &s:graph2[tmp.u]){
                if(cost1[i][s.v]>cost1[i][tmp.u]+s.w){
                    cost1[i][s.v]=cost1[i][tmp.u]+s.w;
                    bfs.push({cost1[i][s.v],s.v});
                }
            }
        }
    }
    /*
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            printf("%lld ",cost1[i][j]);
        }
        printf("\n");
    }
    */
    //solve
    while(q--){
        ll x=read(),y=read();
        x+=n;y+=n;
        ll ret=0x3f3f3f3f3f3f3f3f;
        for(const edge &s1:graph[x]){
            for(const edge &s2:graph[y]){
                ret=min(ret,s1.w+s2.w+cost1[s1.v][s2.v]);
            }
        }
        ret+=(inner_cost1[x-n]+inner_cost1[y-n]);
        printf("%lld\n",ret);
    }
    return 0;
}
