#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define pii pair<int,long long>
using namespace std;
const int N=5e5+11;
vector<pii> g[N];
int c,n,m,d,q,w[N],k[N],t[N],x,y,s[N];
int dis[N];
bool vis[N];
int dij(int x,int y){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    memset(dis,0x3f,sizeof dis);
    dis[x]=0;
    q.push({0,x});
    while(!q.empty()){
        int u=q.top().se;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto &e:g[u]){
            int v=e.fi;
            long long w=e.se;
            if(!vis[v]&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    rep(i,1,m) scanf("%d",w+i);
    rep(i,1,n){
        scanf("%d",k+i);
        rep(j,1,k[i]){
            cin>>s[j]>>t[s[j]];
        }
        rep(j,1,k[i]){
            rep(rp,j+1,k[i]){
                int u=s[j],v=s[rp];
                long long w=t[u]+t[v];
                g[u].push_back({v,w});
                g[v].push_back({u,w});
            }
        }
    }
    /*
    int u=4;
    for(auto e:g[u]){
        int v=e.fi,w=e.se;
        cout<<u<<" "<<v<<" "<<w;
    }*/
    rep(i,1,q){
        scanf("%d%d",&x,&y);
        memset(vis,0,sizeof vis);
        int ans=dij(x,y)+w[x]+w[y];
        printf("%d\n",ans);
    }
    return 0;
}
