#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=5e5+5e2+10;
const int K=15e2+10;
const int M=5e5+10;
struct node_que{
    int id,dist;
    bool operator < (const node_que &b) const{
        return dist>b.dist;
    }
};
priority_queue<node_que>pq;
vector<pii>edge[N];
vector<int>pos[M];
int dist[K][K];
bool vis[K];
int w[M];
// int k[M];
void dijkstra(int st,int len,int *dis){
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
    for(int i=1;i<=len;i++){vis[i]=0;dis[i]=1e18;}
    dis[st]=0;
    pq.push({st,0});
    while(!pq.empty()){
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        int front=pq.top().id;pq.pop();
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        if(vis[front])continue;
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        vis[front]=1;
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        for(auto i:edge[front])
            if(dis[i.first]>dis[front]+i.second){
                dis[i.first]=dis[front]+i.second;
                pq.push({i.first,dis[i.first]});
            }
    }
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
    return ;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    if(c<=11){
        for(int i=1;i<=n;i++){
            int ki=read(),st=i+m;
            for(int j=1;j<=ki;j++){
                int aij=read(),tij=read();
                edge[st].push_back({aij,tij});
                edge[aij].push_back({st,tij});
            }
        }
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        for(int i=1;i<=m;i++)dijkstra(i,n+m,dist[i]);
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        while(q--){
            int x=read(),y=read();
            printf("%lld\n",dist[x][y]+w[x]+w[y]);
        }
    }else if(c<=19){
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        int T=0;
        for(int i=1;i<=n;i++){
            int ki=read();
            for(int j=1;j<=ki;j++){
                int aij=read(),tij=read();T=tij;
                for(auto j:pos[aij])edge[i].push_back({j,2*tij});
                pos[aij].push_back(i);
            }
        }
        for(int i=1;i<=n;i++)dijkstra(i,n,dist[i]);
        // cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        while(q--){
            int x=read(),y=read(),ans=1e18;
            for(auto i:pos[x])for(auto j:pos[y]){ans=min({ans,dist[i][j],dist[j][i]});}
            printf("%lld\n",ans+w[x]+w[y]+2*T);
        }
    }
    return 0;
}
