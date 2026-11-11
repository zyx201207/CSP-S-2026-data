#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500010],b[500010],w[500010],dis[500010];
bool vis[500010];
struct node{
    int v,w;
    friend bool operator<(node a,node b){
        return a.w>b.w;
    }
};
vector<node>G[500010];
int dijsktra(int st){
    priority_queue<node>q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    vis[st]=1;
    dis[st]=0;
    q.push({st,dis[st]});
    while(!q.empty()){
        node now=q.top();
        q.pop();
        int u=now.v;
        //if(vis[u])
            //continue;
        //vis[u]=1;
        for(auto e:G[u]){
            int v=e.v,w=e.w;
            //if(vis[v])continue;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c;
    if(6<c&&c<12){
        cin>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)
            cin>>w[i];
        for(int i=1;i<=n;i++){
            int k,l,r,tl,tr;
            cin>>k>>l>>r>>tl>>tr;
            G[l].push_back({r,tl+tr});
            G[r].push_back({l,tl+tr});
        }
    }
    while(q--){
        int s,l;
        cin>>s>>l;
        dijsktra(s);
        cout<<w[s]+dis[l]+w[l]<<'\n';
    }
    return 0;
}
