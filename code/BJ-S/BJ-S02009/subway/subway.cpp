#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+505;
int c,n,m,d,q,w[N],k[N],ans[N],dis[N],s,vis[N];
struct node{
    int v,w;
};
vector<node> x[N];
bool operator <(node a,node b){
    return a.w>b.w;
}
void dijkstra(){
    priority_queue<node> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        node now=q.top();
        q.pop();
        if(vis[now.v]){
            continue;
        }
        vis[now.v]=1;
        for(auto i:x[now.v]){
            if(dis[i.v]>now.w+i.w){
                dis[i.v]=now.w+i.w;
                q.push({i.v,dis[i.v]});
            }
        }
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int y,z;cin>>y>>z;
            x[y].push_back({m+i,z});
            x[m+i].push_back({y,z});
        }
    }
    // for(int i=1;i<=m;i++){
    //     cout<<i<<":\n";
    //     for(auto j:x[i]){
    //         cout<<j.v-m<<" "<<j.w<<"\n";
    //     }
    //     cout<<"\n";
    // }
    for(int i=1;i<=q;i++){
        int e;
        cin>>s>>e;
        dijkstra();
        // cout<<s<<" ";
        // for(int i=1;i<=m;i++){
        //     cout<<"zhan="<<i<<" "<<dis[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=1;i<=n;i++){
        //     cout<<"xian="<<i<<" "<<dis[i+m]<<" ";
        // }
        // cout<<"\n";
        cout<<dis[e]+w[e]+w[s]<<"\n";
    }
    return 0;
    //ttwmfuheba
}