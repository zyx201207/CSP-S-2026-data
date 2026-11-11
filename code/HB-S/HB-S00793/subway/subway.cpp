#include<bits/stdc++.h>
#define ll long long
#define F(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
int a;
constexpr int M=5e4+2;
constexpr int N=502;
constexpr int K=1e5+10;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,tot;
int w[M];
int t[N][M];
int timer,vis[K],e;
ll ans,res;
struct Edge{
    int to,k,nxt;
}edge[M<<2];
int head[N],cnt;
inline void init(){
    memset(head,-1,sizeof(int)*(m+5));
}
inline void add_edge(int u,int v,int k){
    edge[cnt]={v,k,head[u]};
    head[u]=cnt;
    ++cnt;
}
void dfs(int u,int id,ll sum){;
    if(sum>=res) return;
    if(u==e){
        if(sum+t[id][e]>=res) return;
        res=sum+t[id][e];
        return;
    }
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to,k=edge[i].k;
        if(vis[v]==timer) continue;
        if(k!=id){
            ll nsum;
            if(id==0) nsum=sum+t[k][u];
            else nsum=sum+t[k][u]+t[id][u];
            if(nsum>=res) continue;
            vis[v]=timer;
            dfs(v,k,nsum);
            vis[v]=0;
        }
        else{
            vis[v]=timer;
            dfs(v,id,sum);
            vis[v]=0;
        }
    }
}
int b;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    int u=0,v=0;
    init();
    F(i,1,m) cin>>w[i];
    F(i,1,n){
        cin>>tot;
        u=0,v=0;
        F(j,1,tot){
            cin>>v>>t[i][v];
            if(u!=0){
                add_edge(u,v,i);
                add_edge(v,u,i);
            }
            u=v;
        }
    }
    // F(i,1,m){
    //     for(int j=head[i];j!=-1;j=edge[j].nxt){
    //         int k=edge[j].to,kk=edge[j].k;
    //         cout<<i<<"->"<<kk<<"->"<<k<<'\n';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        cin>>u>>v;
        ans=w[u]+w[v];
        e=v;
        ++timer;
        res=INF;
        vis[u]=timer;
        dfs(u,0,0LL);
        cout<<ans+res<<'\n';
    }
}