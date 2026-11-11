#include<bits/stdc++.h>
#define int long long
using namespace std;

int CASE,n,m,D,qu;
int w[500010];
struct node{
    int id,t;
};
vector<node> v[500010];
int f[510][510],d[510][510];
bool vis[510][510];
struct edge{
    int v,w;
};
vector<edge> g[510];
struct node2{
    int u,d;
    bool operator>(const node2& t)const{
        return d>t.d;
    }
};
priority_queue<node2,vector<node2>,greater<node2>> pq;

inline void upd(int& x,int y){
    if(x==-1){
        x=y;
        return;
    }
    x=min(x,y);
    return;
}

void dijk(int s){
    for(int i=1;i<=n;i++) d[s][i]=LLONG_MAX;
    pq.push({s,0});
    d[s][s]=0;
    while(!pq.empty()){
        node2 now=pq.top();
        pq.pop();
        if(vis[s][now.u]) continue;
        vis[s][now.u]=1;
        for(edge e:g[now.u]){
            if(d[s][now.u]+e.w<d[s][e.v]){
                d[s][e.v]=d[s][now.u]+e.w;
                pq.push({e.v,d[s][e.v]});
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>CASE>>n>>m>>D>>qu;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int id,t;
            cin>>id>>t;
            v[id].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int p=0;p<v[i].size();p++){
            for(int q=p+1;q<v[i].size();q++){
                node pp=v[i][p],qq=v[i][q];
                upd(f[pp.id][qq.id],pp.t+qq.t);
                f[qq.id][pp.id]=f[pp.id][qq.id];
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i][j]!=-1) {
                g[i].push_back({j,f[i][j]});
                g[j].push_back({i,f[i][j]});
            }
        }
    }
    for(int i=1;i<=n;i++) dijk(i);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            if(d[i][j]==LLONG_MAX) d[i][j]=-1;
        }
        d[i][i]=0;
    }
    while(qu--){
        int x,y;
        cin>>x>>y;
        int ans=LLONG_MAX;
        for(int i=0;i<v[x].size();i++){
            for(int j=0;j<v[y].size();j++){
                node p=v[x][i],q=v[y][j];
                if(d[p.id][q.id]!=-1)
                    ans=min(ans,d[p.id][q.id]+p.t+q.t);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }

    return 0;
}
