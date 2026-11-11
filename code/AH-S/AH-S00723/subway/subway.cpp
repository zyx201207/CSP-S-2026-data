#include<bits/stdc++.h>
using namespace std;
long long h[500005],vtx[500005],nxt[500005],wt[500005],idx;
void add(long long a,long long b,long long c){
    vtx[idx]=b;
    wt[idx]=c;
    nxt[idx]=h[a];
    h[a]=idx;
    idx++;
}
struct z{
    long long u,v,w;
    bool operator<(z a) const{
        return a.w<w;
    }
};
long long c,n,m,d,e,t[500005],k,a[500005],w[500005],x,y;
long long dis[500005];
bool vis[500005];
priority_queue<z> q;
void dij(long long s){
    z tmp;
    tmp.u=s;
    tmp.v=s;
    tmp.w=0;
    q.push(tmp);
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        long long nid=tmp.v;
        if(vis[nid]==1){
            continue;
        }
        vis[nid]=1;
        long long p=h[nid];
        while(p!=-1){
            if(vis[vtx[p]]==0){
                if(dis[vtx[p]]>=dis[nid]+wt[p]){
                    dis[vtx[p]]=dis[nid]+wt[p];
                    tmp.u=nid;
                    tmp.v=vtx[p];
                    tmp.w=dis[vtx[p]];
                    q.push(tmp);
                }
            }
            p=nxt[p];
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(h,-1,sizeof(h));
    cin>>c>>n>>m>>d>>e;
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>w[j];
        }
        for(int j=1;j<k;j++){
            for(int l=j+1;l<=k;l++){
                add(a[j],a[l],w[j]+w[l]);
                add(a[l],a[j],w[j]+w[l]);
            }
        }
    }
    while(e--){
        cin>>x>>y;
        for(int i=1;i<=m;i++){
            dis[i]=1e18;
        }
        dis[x]=0;
        memset(vis,0,sizeof(vis));
        dij(x);
        cout<<dis[y]+t[x]+t[y]<<"\n";

    }
    return 0;
}
