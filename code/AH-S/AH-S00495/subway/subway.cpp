#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
long long w[500005],k[505],a[505][500005],t[505][500005],zl,zr,ans=1e18;
vector<long long> v[500005];
bool vis[500005][505];
//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。
void bfs(long long qd,long long mb,long long sj){
    queue<long long> q;
    q.push(qd);
    if(qd==mb){
        ans=min(ans,sj+w[qd]);
    }
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            if(!vis[u][v[u][i]]){
                bfs(u,mb,sj+t[v[u][i]][u]);
                q.push(v[u][i]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%lld",w[i]);
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            scanf("%lld %lld",&a[i][j],&t[i][j]);
        }
    }
    while(q--){
        cin>>zl>>zr;
        memset(vis,0,sizeof(vis));
        ans=1e18;
        bfs(zl,zr,w[zl]);
        cout<<ans<<endl;
    }
    return 0;
}
