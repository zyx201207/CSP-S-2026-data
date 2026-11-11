#include<bits/stdc++.h>
using namespace std;
const long long D=1e18+5,define=0;
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>dl;
vector<int>p[150005],points[1005];
vector<long long>l[150005],lines[1005];
int c,n,m,d1,q,k[1005];
long long w[150005],f[1005][1005],d[1005];
bool vis[1005];
void init(){
    for(int i=1;i<=m;i++){
        for(int j=0;j<p[i].size();j++){//
            for(int x=j+1;x<p[i].size();x++){////
                if(f[p[i][j]][p[i][x]]==0){
                    f[p[i][j]][p[i][x]]=l[i][j]+l[i][x];
                    f[p[i][x]][p[i][j]]=l[i][j]+l[i][x];
                }
                else {
                    f[p[i][j]][p[i][x]]=min(f[p[i][j]][p[i][x]],l[i][j]+l[i][x]);
                    f[p[i][x]][p[i][j]]=min(f[p[i][x]][p[i][j]],l[i][j]+l[i][x]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(define) cout<<f[i][j]<<" ";
            if(i==j) continue;
            if(f[i][j]!=0){
                points[i].push_back(j);
                lines[i].push_back(f[i][j]);
            }
        }
        if(define) cout<<endl;
    }
    return;
}
void build(int x,int y){
    for(int i=0;i<p[x].size();i++){
        points[n+1].push_back(p[x][i]);
        lines[n+1].push_back(l[x][i]);
    }
    for(int i=0;i<p[y].size();i++){
        points[p[y][i]].push_back(n+2);
        lines[p[y][i]].push_back(l[y][i]);
    }
    return;
}
void rebuild(int y){
    while(points[n+1].size()>0){
        points[n+1].pop_back();
        lines[n+1].pop_back();
    }
    for(int i=0;i<p[y].size();i++){
        points[p[y][i]].pop_back();
        lines[p[y][i]].pop_back();
    }
    return;
}
int findmin(){
    pair<long long,int>th;
    while(!dl.empty()){
        th=dl.top();
        dl.pop();
        if(vis[th.second]==0){
            vis[th.second]=1;
            return th.second;
        }
    }
    return -1;
}
void relax(int u,int v,long long wt){
    if(d[u]+wt<d[v]){
        d[v]=d[u]+wt;
        pair<long long,int>th={d[v],v};
        dl.push(th);
    }
    return;
}
void dj(int s,int e){
    int N=n+2;
    for(int i=1;i<=N;i++){
        vis[i]=0;
        d[i]=D;
    }
    while(!dl.empty()) dl.pop();
    d[s]=0;
    pair<long long,int>th={d[s],s};
    dl.push(th);
    while(!dl.empty()){
        int x=findmin();
        if(x==-1) break;
        for(int i=0;i<points[x].size();i++){
            relax(x,points[x][i],lines[x][i]);
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // cin>>c>>n>>m>>d1>>q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d1,&q);
    for(int i=1;i<=m;i++){
        // cin>>w[i];
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        // cin>>k[i];
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            int a;
            long long t;
            scanf("%d%lld",&a,&t);
            p[a].push_back(i);
            l[a].push_back(t);
        }
    }
    init();
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        build(x,y);
        dj(n+1,n+2);
        // cout<<d+2]+[nw[x]+w[y]<<endl;
        printf("%lld\n",d[n+2]+w[x]+w[y]);
        rebuild(y);
    }
}