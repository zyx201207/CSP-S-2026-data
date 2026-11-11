#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5,mod=1e9+7,INF=1e9+10,N=505,Q=1e5+5;
int w[M];
struct node{
    int v,id;
};
int c,n,m,d,q;
vector<node> b[M];
int t[N][M];
ll dis[M];
bool vis[M];
void djstl(int u){
    queue<node> q;
    node qi;
    qi.id=u;
    qi.v=0;
    q.push(qi);
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[u]=w[u];
    vis[u]=1;
    while(!q.empty()){
        node id=q.front();
        vis[id.id]=0;
        q.pop();
        for(int i=0;i<b[id.id].size();i++){
            int y=b[id.id][i].v;
            int x=t[b[id.id][i].id][y]+t[b[id.id][i].id][id.id];
            if(dis[y]>dis[id.id]+x){
                dis[y]=dis[id.id]+x;
                if(!vis[y]){
                    vis[y]=1;
                    qi.id=y;
                    qi.v=b[id.id][i].id;
                    q.push(qi);
                }
            }
        }
    }
}
int a[M];
struct nodee{
    int u,v,id;
} xz[Q];
bool cmp(nodee xxx,nodee yyy){
    return xxx.u<yyy.u;
}
int ans[Q];
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
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[i][a[j]];
            if(j==1){
                continue;
            }
            for(int l=1;l<j;l++){
                b[a[j]].push_back({a[l],i});
                b[a[l]].push_back({a[j],i});
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>xz[i].u>>xz[i].v;
        xz[i].id=i;
    }
    sort(xz+1,xz+q+1,cmp);
    for(int i=1;i<=q;i++){
        if(xz[i].u!=xz[i-1].u)djstl(xz[i].u);
        ans[xz[i].id]=dis[xz[i].v]+w[xz[i].v];
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}

