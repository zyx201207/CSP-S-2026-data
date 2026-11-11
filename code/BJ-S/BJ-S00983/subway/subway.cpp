#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000;
const int inf=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;

struct node{
    int to,w;
};
vector <node> mp[N];
int vis[N][N],dis[N][N];
struct edge{
    int z,dist;
    bool operator <(const edge other) const{
        return dist>other.dist;
    }
};
void dij(int s){
    for (int i=1;i<=m;i++){
        vis[s][i]=0;
        dis[s][i]=inf;
    }
    priority_queue <edge> q;
    q.push({s,0});
    dis[s][s]=0;
    while (!q.empty()){
        int u=q.top().z;
        q.pop();
        if (vis[s][u]) continue;
        vis[s][u]=1;
        for (int i=0;i<mp[u].size();i++){
            int v=mp[u][i].to,w=mp[u][i].w;
            if (dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                q.push({v,dis[s][v]});
            }
        }
    }
}
int a[N],t[N];
int w[N];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (x==1) continue;
        for (int j=1;j<=x;j++){
            cin>>a[j]>>t[j];
        }
        for (int j=1;j<=x;j++){
            for (int k=1;k<=x;k++){
                if (j==k) continue;
                mp[a[j]].push_back({a[k],t[j]+t[k]});
                mp[a[k]].push_back({a[j],t[j]+t[k]});
            }
        }
    }
    for (int i=1;i<=n;i++){
        dij(i);
    }
    for (int i=1;i<=q;i++){
        int s,ed;
        cin>>s>>ed;
        cout<<dis[s][ed]+w[s]+w[ed]<<'\n';
    }
}
