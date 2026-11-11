#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
struct node{
    ll v,w;
};
ll c,m,n,D,Q;
const int M=501000;
const int N=510;
vector<node>g[M+N];
ll w[M],k[N],a,t,d[M+N];
bool vis[M];
struct InPut{
    ll x,y,id,ans;
    bool operator<(const InPut &a)const{
        return x<a.x;
    }
}in[100010];
void dij(ll s){
    memset(d,0x3f,sizeof d);
    memset(vis,0,sizeof vis);
    d[s]=0;
    q.push({0,s});
    while(!q.empty()){
        auto k=q.top();
        q.pop();
        int u=k.second;
        if(vis[u])continue;
        vis[u]=true;
        for(auto i:g[u]){
            int v=i.v;
            int w=i.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
bool cmp(const InPut &a,const InPut &b){
    return a.id<b.id;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&Q);
    for(int i=1;i<=m;i++){
        scanf("%lld",w+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",k+i);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&a,&t);
            g[500000+i].push_back({a,t});
            g[a].push_back({500000+i,t});
        }
    }
    //for(int i=1;i<=m;i++){
    //    for(auto j:g[i]){
    //        printf("%d %lld %lld  ",i,j.v,j.w);
    //    }
    //    puts("");
    //}
    for(int i=1;i<=Q;i++){
        scanf("%lld%lld",&in[i].x,&in[i].y);
        //dij(in[i].x);
        //in[i].ans=d[in[i].y];
        //in[i].ans+=w[in[i].x]+w[in[i].y];
        //printf("%lld\n",in[i].ans);
        in[i].id=i;
    }
    sort(in+1,in+1+Q);
    for(int i=1;i<=Q;i++){
        if(in[i].x==in[i-1].x){
            in[i].ans=d[in[i].y];
            continue;
        }
        dij(in[i].x);
        in[i].ans=d[in[i].y];
    }
    sort(in+1,in+1+Q,cmp);
    for(int i=1;i<=Q;i++){
        in[i].ans+=w[in[i].x]+w[in[i].y];
        printf("%lld\n",in[i].ans);
    }
    return 0;
}
/*
0 2 5 20 2
1 1 1 1 1
3 1 2 2 3 3 4
3 1 4 2 2 3 3
2 3

*/
