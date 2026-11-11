#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m1,c,d1,q1,p[500005],dis[510000];
struct node{
    int vi,wi;
    bool operator<(const node &h)const{
        return wi>h.wi;
    }
};
int k;
vector<node>s[510000];
priority_queue<node> q;
void dijkstra(int v){
    memset(dis,0x3f,sizeof(dis));
    q.push({v,0});
    dis[v]=0;
    while(!q.empty()){
        node h=q.top();q.pop();
        int v=h.vi;
        for(int i=0;i<s[v].size();i++){
            int u=s[v][i].vi;
            if(dis[u]>dis[v]+s[v][i].wi){
                dis[u]=dis[v]+s[v][i].wi;
                q.push({u,dis[u]});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m1>>d1>>q1;
    for(int i=1;i<=m1;i++){
        cin>>p[i];
    }
    k=m1;
    for(int i=1;i<=n;i++){
        int ki;
        cin>>ki;
        for(int j=1;j<=ki;j++){
            int vi,ti;
            cin>>vi>>ti;
            s[vi].push_back({++k,ti});
            s[k].push_back({vi,ti});
            if(j!=1){
                s[k].push_back({k-1,0});
                s[k-1].push_back({k,0});
            }
        }
    }
    while(q1--){
        int u,v;
        cin>>u>>v;
        dijkstra(u);
        cout<<dis[v]+p[u]+p[v]<<'\n';
    }
    return 0;
}
