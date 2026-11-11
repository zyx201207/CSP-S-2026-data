#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,w[500005],u[500005],v[500005],allu[500005];

struct node{
    long long v,w;
    bool operator < (const node &b) const{
        return w>b.w;
    }
};
map<long long,vector<node>> g;
map<long long,long long> dis;
map<long long,map<long long,long long>> ans;
priority_queue<node> pq;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        g[i].push_back({m+i,w[i]});
        g[m+i].push_back({i,w[i]});
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a,t,lst;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            g[m*(i+1)+a].push_back({m+a,t});
            g[m+a].push_back({m*(i+1)+a,t});
            if(j>1){
                g[m*(i+1)+lst].push_back({m*(i+1)+a,0});
                g[m*(i+1)+a].push_back({m*(i+1)+lst,0});
            }
            lst=a;
        }
    }
    for(int i=1;i<=m;i++){
        dis.clear();
        pq.push({i,0});
        dis[i]=0;
        while(!pq.empty()){
            long long u=pq.top().v;
            pq.pop();
            for(int idx=0;idx<g[u].size();idx++){
                int v=g[u][idx].v,w=g[u][idx].w;
                if(!dis.count(v)||dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    ans[i][v]=dis[v];
                    pq.push({v,dis[v]});
                }
            }
        }
        while(!pq.empty()) pq.pop();
    }
    for(int i=1;i<=q;i++){
        cin>>u[i]>>v[i];
        cout<<ans[u[i]][v[i]]<<"\n";
    }
    return 0;
}
