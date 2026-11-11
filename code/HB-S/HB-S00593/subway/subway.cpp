#include<bits/stdc++.h>
using namespace std;
long long xxkan[500010]={0};
struct edge{
    int to;
    int next;
    long long v;
};
edge ed[500010];
int cnt=0;
int head[510]={0};
inline void in(int u,int v,long long w){
    ed[++cnt]={v,head[u],w};
    head[u]=cnt;
}

struct point{
    long long dis;
    int id;
    bool operator<(const point &x)const{
        return dis>x.dis;

    }
};
struct node{
    int id;
    long long v;
};
vector<node> e[500010];
long long f[510][510]={0};
long long dis[510]={0};
bool vis[510]={0};
long long g[510][510]={0};
priority_queue<point> q;

inline void dj(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push((point){
        0,s
    });
    while(!q.empty()){
        point now=q.top();
        q.pop();
        int x=now.id;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=ed[i].next){
            int y=ed[i].to;
            if(dis[y]>dis[x]+ed[i].v){
                dis[y]=dis[x]+ed[i].v;
                if(!vis[y]){
                    q.push((point){
                        dis[y],y
                    });
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(f,0x3f,sizeof(f));
    memset(g,0x3f,sizeof(g));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>xxkan[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            e[x].push_back((node){i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(node l:e[i]){
            for(node r:e[i]){
                g[l.id][r.id]=min(g[l.id][r.id],l.v+r.v);

            }
        }


    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(g[i][j]<0x3f3f3f3f3f3f3f3f){
                in(i,j,g[i][j]);
                in(j,i,g[j][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        dj(i);
        for(int j=1;j<=n;j++){
            f[i][j]=dis[j];
            
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=1000000000000000000;
        for(node u:e[x]){
            for(node v:e[y]){
                ans=min(ans,f[u.id][v.id]+u.v+v.v);
            }
        }
        cout<<ans+xxkan[x]+xxkan[y]<<'\n';
    }
    return 0;
}