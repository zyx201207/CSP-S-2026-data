#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll const INF=(1LL<<62);
int c,n,m,d,q,tot,k,head[1005500],nxt[1005500],ver[1005500],used[1005500];
ll edge[1005500],dist[550000],w[550000],dst,t;
void add(int x,int y,ll z){
    ver[++tot]=y;edge[tot]=z;
    nxt[tot]=head[x];head[x]=tot;
    ver[++tot]=x;edge[tot]=z;
    nxt[tot]=head[y];head[y]=tot;
}
struct cmp{
    bool operator()(const pair<int,ll> & p1,const pair<int,ll> & p2)const{
        return p1.second>p2.second;
    }
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    int a,x,y,u;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            add(m+i,a,t);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        for(int j=1;j<=m+n;j++)dist[j]=INF;
        memset(used,0,sizeof(used));
        dist[x]=0;
        priority_queue<pair<int,ll>,vector<pair<int,ll>>,cmp> pq;
        pq.push({x,dist[x]});
        while(!pq.empty()){
            u=pq.top().first;
            dst=pq.top().second;
            pq.pop();
            if(used[u])continue;
            used[u]=1;
            for(int v=head[u];v;v=nxt[v]){
                if(!used[ver[v]] && dist[ver[v]]>=dst+edge[v]){
                    dist[ver[v]]=dst+edge[v];
                    pq.push({ver[v],dist[ver[v]]});
                }
            }
        }
        cout<<dist[y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
