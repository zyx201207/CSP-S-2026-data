#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+505;
const long long INF=2e18;
struct Node{
    int v,w;
};
vector<Node>eg[MAXN],eg1[MAXN];
ll w[MAXN],dep[505],dis[505][505];
bool vis[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            eg[a].push_back({m+i,t});
            eg[m+i].push_back({a,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto[v1,w1]:eg[i]){
            for(auto[v2,w2]:eg[i]){
                if(v1==v2)continue;
                eg1[v1-m].push_back({v2-m,w1+w2});
                eg1[v2-m].push_back({v1-m,w1+w2});
            }
        }
    }
    for(int i=1;i<=n;i++){
        memset(dep,0x3f,sizeof(dep));
        memset(vis,0,sizeof(vis));
        priority_queue<pair<ll,int>>q;
        q.push({0,i});
        dep[i]=0;
        while(!q.empty()){
            int x=q.top().second;
            q.pop();
            if(vis[x])continue;
            vis[x]=1;
            for(auto[v,w]:eg1[x]){
                if(dep[x]+w<dep[v]){
                    dep[v]=dep[x]+w;
                    q.push({-dep[v],v});
                }
            }
        }
        for(int j=1;j<=n;j++){
            dis[i][j]=dep[j];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        ll ans=INF;
        scanf("%d%d",&x,&y);
        for(auto[v1,w1]:eg[x]){
            for(auto[v2,w2]:eg[y]){
                ans=min(ans,w[x]+w[y]+w1+w2+dis[v1-m][v2-m]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
