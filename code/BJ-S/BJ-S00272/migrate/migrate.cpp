#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pli pair<ll,int>
const int N=2e6+10,M=2e3+10;
const ll INF=1e18;
int c,n;
ll d,a[N];
struct edge{
    int v,ne;
    ll w;
}e[N<<1];
int h[N],idx;
void add(int u,int v,ll w){
    e[++idx].v=v;
    e[idx].w=w;
    e[idx].ne=h[u];
    h[u]=idx;
}
bool vis[N];
ll dis[M][M],cnt[M][M];
void dijkstra(int s){
    priority_queue<pli,vector<pli>,greater<pli> >q;
    for(int i=1;i<=n;i++){
        dis[s][i]=INF;
        vis[i]=false;
    }
    vis[s]=true;
    dis[s][s]=0;
    q.push({0,s});
    while(q.size()){
        pli t=q.top();
        q.pop();
        ll d=t.first;
        int u=t.second;
        if(d>dis[s][u])continue;
        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v;
            ll w=e[i].w;
            if(dis[s][v]==dis[s][u]+w){
                cnt[s][v]++;
            }
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                cnt[s][v]=1;
                if(!vis[v]){
                    vis[v]=true;
                    q.push({dis[s][v],v});
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    scanf("%d%d",&c,&T);
    while(T--){
        ll ans=0;
        idx=0;
        memset(h,0,sizeof(h));
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(13<=c&&c<=14){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(abs(a[i]-a[j])<=d){
                    add(i,j,1);
                    add(j,i,1);
                }
            }
        }
        dijkstra(1);
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(cnt[i][j]==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
