#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct edge{
    int to,w;
};
int n,m,d,q,a[N],dis[N],st[N],ed[N];
vector<edge> e[N];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int h=q.front();q.pop();
        for(int i=0;i<e[h].size();i++){
            edge g=e[h][i];
            if(dis[g.to]>dis[h]+g.w){
                dis[g.to]=dis[h]+g.w;
                q.push(g.to);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1,u,v,h,t;i<=n;i++){
        cin>>u>>u>>h>>v>>t;
        e[u].push_back({v,h+t});
    }
    for(int i=1;i<=q;i++) cin>>st[i]>>ed[i];
    for(int i=1;i<=q;i++){
        dij(st[i]);
        cout<<dis[ed[i]]+a[st[i]]+a[ed[i]]<<endl;
    }
    return 0;
}
