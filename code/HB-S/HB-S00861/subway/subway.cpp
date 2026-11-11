#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
int change[500005][505];
int line[500005][25];
vector<pair<int,int> > g[500005];//id&v
int c,n,m,d,q;
int tx,ty,ans;
bool inq[500005];
int dist[500005];
int eli;
int sli[500005];
void dij(int st,int end){
    //cout<<1<<' ';
    for(int i=1;i<=500000;i++){
        dist[i]=INT_MAX;
        inq[i]=0;
        sli[i]=0;
        eli=0;
    }
    dist[st]=0;
    queue<pair<int,int>> q;//id&v
    q.push({-1,st});
    inq[st]=1;
    //cout<<1<<' ';
    while(!q.empty()){
        pair<int,int> point=q.front();
        q.pop();
        int id=point.first,u=point.second;
        //cout<<u<<'\n';
        //inq[u]=0;
        //cout<<1<<'\n';
        for(int i=0;i<g[u].size();i++){
            int edge=g[u][i].first,v=g[u][i].second;
            //cout<<edge<<' '<<v<<'\n';
            if(id==-1 || id==edge){
                if(dist[v]>=dist[u] || dist[v]==0){
                    dist[v]=dist[u];
                    if(u==st){
                        sli[v]=edge;
                    }else{
                        sli[v]=sli[u];
                    }
                    if(v==end) eli=edge;
                    if(inq[v]==0){
                        q.push({edge,v});
                        inq[v]=1;
                    }
                }
            }else{
                if(dist[v]>=dist[u]+change[u][id]+change[u][edge] || dist[v]==0){
                    dist[v]=dist[u]+change[u][id]+change[u][edge];
                    sli[v]=sli[u];
                    if(v==end) eli=edge;
                    if(inq[v]==0){
                        q.push({edge,v});
                        inq[v]=1;
                    }
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<' ';
    // }
    // cout<<'\n';
    //cout<<1<<'\n';
    tx=sli[end];
    ty=eli;
    ans=dist[end];
}
signed main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    //cout<<1<<' ';
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int las=-1;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            change[a][i]=t;
            if(las!=-1){
                pair<int,int> q={i,a},p={i,las};
                g[las].push_back(q);
                g[a].push_back(p);
            }
            las=a;
            line[a][0]++;
            line[a][line[a][0]]=i;
        }
    }
    //cout<<1<<' ';
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ans=0;
        dij(x,y);
        //cout<<tx<<' '<<ty<<'\n';
        //cout<<ans<<'\n';
        cout<<ans+w[x]+w[y]+change[x][tx]+change[y][ty]<<'\n';
    }
}
//this problem is the most beutiful problem in CSP-S2!