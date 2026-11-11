#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
const int D=25;
const long long INF=1e17;
int C,n,m,d,Q;
int prw[M];
int k[N];
int head[M+N],to[(M*D)<<1],nxt[(M*D)<<1],cnt;
long long w[(M*D)<<1];
void add(int u,int v,long long W)
{
    to[++cnt]=v;
    w[cnt]=W;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
struct node
{
    int id;
    int t;//
};
int siz[M];
long long dis[M];
struct movenode
{
    int u;
    long long d;
    bool operator <(const movenode &b) const
    {
        return d > b.d ;
    }
};
priority_queue<movenode> q;
void dij(int s)
{
    for(int i=1;i<=m+n;i++)
        dis[i]=INF;
    dis[s]=0;
    q.push((movenode){s,0});
    while(!q.empty()){
        movenode x=q.top();
        q.pop();
        int u=x.u;
        if(dis[u]!=x.d)
            continue;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(dis[v]>dis[u]+w[i]){
                dis[v]=dis[u]+w[i];
                q.push((movenode){v,dis[v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>prw[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,a,t;j<=k[i];j++){
            cin>>a>>t;
            add(a,m+i,t);
            add(m+i,a,t);
        }
    }
    for(int T=1,u,v;T<=Q;T++){
        cin>>u>>v;
        dij(u);
        cout<<dis[v]+prw[u]+prw[v]<<'\n';
    }
    return 0;
}
