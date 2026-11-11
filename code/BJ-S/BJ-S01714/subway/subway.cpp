#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,k,q,w[500005],dis[505];
struct node{
    int first,second;
};
node make_pair(int x,int y){
    return (node){x,y};
}
vector <node> line[505];
vector <node> pline[500005];
int dijkstra(int sl,int el){
    for(int i=1;i<=n;++i) dis[i]=LONG_LONG_MAX;
    queue <int> q;
    q.emplace(sl);
    dis[sl]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto i:line[now]){
            int tmpd=dis[now]+i.second;
            if(tmpd<dis[i.first]){
                dis[i.first]=tmpd;
                q.push(i.first);
            }
        }
    }
    return dis[el];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j){
            int u,t;
            cin>>u>>t;
            for(auto p:pline[u]){
                line[i].emplace_back(make_pair(p.first,p.second+t));
                line[p.first].emplace_back(make_pair(i,p.second+t));
            }
            pline[u].emplace_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=q;++i){
        int x,y,ans=LONG_LONG_MAX;
        cin>>x>>y;
        for(auto i:pline[x]){
            for(auto j:pline[y]){
                int res=w[x]+w[y]+i.second+j.second;
                res+=dijkstra(i.first,j.first);
                ans=min(ans,res);
            }
        }
        cout<<ans<<"\n";
    }
    cout.flush();
    return 0;
}