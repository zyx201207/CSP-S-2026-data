#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int M = 5e5+5;
const int N = 505;
int n,m,d,q,c;
int w[M];
vector<int> a[M],t[M];
vector<long long> ms[M],mt[M];
int k[N];
struct edge{
    int to,nxt,w;
}e[M];
struct edgs{
    long long p,dist;
};
int head[N],vis[N];
long long nt[N][N],ds[N][N];
long long dis[N];
int cnt;
long long ans;
void add(int u,int v,int w){
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void djstl(int x){
    for(int i=1;i<=n;i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    queue<edgs> qu;
    qu.push({x,0});
    vis[x] = 1;
    dis[x] = 0;
    while(!qu.empty()){
        edgs fr = qu.front();
        qu.pop();
        vis[fr.p] = 1;
        for(int i=head[fr.p];i!=-1;i=e[i].nxt){
            int v = e[i].to;
            dis[v] = min(dis[v],dis[fr.p]+e[i].w);
            if(!vis[v])qu.push({v,dis[v]});
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){cin>>w[i];}
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int tm;
            long long tt;
            cin>>tm;
            a[i].push_back(tm);
            ms[tm].push_back(i);
            cin>>tt;
            t[i].push_back(tt);
            mt[tm].push_back(tt);
            for(int op=0;op < ms[tm].size()-1;op++){
                nt[i][ms[tm][op]] = min(nt[i][ms[tm][op]],tt+mt[tm][op]);
                nt[ms[tm][op]][i] = nt[i][ms[tm][op]];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            if(nt[i][j]){
                add(i,j,nt[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        djstl(i);
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            ds[i][j] = dis[j];
        }
    }
    ans = INF;
    while(q--){
        int xr,yr;
        cin>>xr>>yr;
        for(int i=0;i<ms[xr].size();i++){
            for(int j=0;j<ms[yr].size();j++){
                ans = min(ans,ds[ms[xr][i]][ms[yr][i]]+mt[xr][i]+mt[yr][j]);
            }
        }
        cout<<ans+w[xr]+w[yr]<<"\n";
    }
    return 0;
}
