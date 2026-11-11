
#include<bits/stdc++.h>
using namespace std;
long long ans,c,d,q,n,m,w[50001];
long long cnt=0,tot=0;
vector<pair<int,int> > e[100001];
int a[501][100001],r[501][100001],k[501];
int iddating[501],mk[501][500001];
bool vis[501][500001];
int dis[50000001];
void bfs(int s){
    queue<pair<int,int> > q;
    memset(dis,0x3f3f3f,sizeof(dis));
    q.push({s,0});
    dis[s]=0;
    while (!q.empty()){
        auto t=q.front();
        q.pop();
        for (int i=0;i<e[t.first].size();i++){
            int v=e[t.first][i].first,u=t.first;
            int w=e[u][i].second;
            if (dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,0});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        int a0,w0;
        for (int j=1;j<=k[i];j++){
            cin>>a[i][j]>>r[i][j];
            long long zero=0;
            if (j!=1){
                e[i*a0].push_back({a[i][j]*i,zero});
                e[i*a[i][j]].push_back({i*a0,zero});
            }
            tot=max(tot,1ll*i*a0);
            tot=max(tot,1ll*i*a[i][j]);
            a0=a[i][j];w0=r[i][j];
            vis[i][a0]=1;mk[i][a0]=w0;
        }
    }
    for (int i=1;i<=m;i++){
        iddating[i]=++tot;
        for (int j=1;j<=n;j++){
            if (vis[j][i]){
                e[tot].push_back({j*i,mk[j][i]});
                e[i*j].push_back({tot,mk[j][i]});
            }
        }
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        bfs(iddating[x]);
        cout<<dis[iddating[y]]+ans<<endl;
    }
    return 0;
}
