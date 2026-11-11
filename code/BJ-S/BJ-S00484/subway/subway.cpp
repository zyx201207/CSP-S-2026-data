#include<bits/stdc++.h>
using namespace std;
const int N=5e7 + 7;
struct p{
    int v,w;
};
vector<p>e[N];
int c,d,q1,n,m,cnt,dis[N],vis[N];
int D(int x,int y){
    queue<int>q;
    q.push(x);
    memset(dis,0x3f,sizeof dis);
    memset(vis,0x3f,sizeof vis);
    dis[x]=0;
    while(!q.empty()){
        int u=q.front();
        for(auto [v,w]:e[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                }
            }
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q1;
    for(int i=1;i<=m;++i){
        int x;
        cin>>x;
        e[i].push_back({i+n,x});
        e[i+n].push_back({i,x});
    }
    for(int i=1;i<=n;++i){
        int k,x,y;
        cin>>k>>x>>y;
        e[x+n].push_back({x+(1+i)*n,y});
        e[x+(1+i)*n].push_back({x+n,y});
        for(int j=2;j<=k;++j){
            int xx,yy;
            cin>>xx>>yy;
            e[x+(1+i)*n].push_back({xx+(1+i)*n,0});
            e[xx+(1+i)*n].push_back({x+(1+i)*n,0});
            e[xx+n].push_back({xx+(1+i)*n,yy});
            e[xx+(1+i)*n].push_back({xx+n,yy});
            x=xx;
            y=yy;
        }
    }
    while(q1--){
        int s,e;
        cin>>s>>e;
        cout<<D(s,e)<<'\n';
    }
    return 0;
}
