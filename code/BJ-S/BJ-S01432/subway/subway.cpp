#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct edge{int to,val;};
void solve(){
    int n,m,d,q;
    cin>>n>>n>>m>>d>>q;
    int w[m+1];
    for(int i=1;i<=m;i++)
        cin>>w[i];
    vector<edge> e[n+m+1];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            e[m+i].push_back({a,t});
            e[a].push_back({m+i,t});
        }
    }
    int dist[m+1][m+n+1];
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        bool is[m+n+1];
        memset(is,0,sizeof(is));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        dist[i][i]=0;
        q.push({0,i});
        while(!q.empty()){
            int now=q.top().second;
            q.pop();
            if(is[now])
                continue;
            for(edge t:e[now]){
                if(dist[i][t.to]>dist[i][now]+t.val){
                    dist[i][t.to]=dist[i][now]+t.val;
                    q.push({dist[i][t.to],t.to});
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dist[x][y]+w[x]+w[y]<<endl;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
