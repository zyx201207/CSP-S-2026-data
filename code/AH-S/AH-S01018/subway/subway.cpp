#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,k,x,y;
int w[N],a[N],t[N];
struct node{
    int l,t;
};
vector<node>g[N];
int bfs(){
    int minn=0x3f3f3f3f;
    bool vis[N];
    for(int i=1;i<=m;i++){
        vis[i]=0;
    }
    queue<node>p;
    while(!p.empty()){
        p.pop();
    }
    for(int i=0;i<g[x].size();i++){
        p.push(g[x][i]);
        vis[g[x][i].l]=1;
    }
    while(!p.empty()){
        node gcl=p.front();
        if(gcl.l==y)minn=min(minn,gcl.t);
        for(int i=0;i<g[gcl.l].size();i++){
            p.push({g[gcl.l][i].l,gcl.t+g[gcl.l][i].t});
            vis[gcl.l]=1;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        if(k==2){
            g[a[1]].push_back({a[2],t[1]+t[2]});
            g[a[2]].push_back({a[1],t[1]+t[2]});
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<bfs()<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
