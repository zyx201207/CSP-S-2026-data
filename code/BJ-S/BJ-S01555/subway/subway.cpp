#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    if(!(cin>>c>>n>>m>>d>>q)) return 0;
    vector<long long> w(m+1);
    for(int i=1;i<=m;i++) cin>>w[i];
    vector<vector<pair<int,long long>>> lineSt(n+1);
    vector<vector<pair<int,long long>>> stLines(m+1);
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=0;j<k;j++){
            int a; long long t; cin>>a>>t;
            lineSt[i].push_back({a,t});
            stLines[a].push_back({i,t});
        }
    }
    vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int v=1;v<=m;v++){
        auto &L=stLines[v];
        int sz=L.size();
        for(int a=0;a<sz;a++){
            for(int b=a+1;b<sz;b++){
                int i=L[a].first, j=L[b].first;
                long long cost=L[a].second + L[b].second;
                if(cost<dist[i][j]){ dist[i][j]=dist[j][i]=cost; }
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++){
            if(dist[i][k]>=INF) continue;
            for(int j=1;j<=n;j++){
                if(dist[k][j]>=INF) continue;
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    while(q--){
        int x,y; cin>>x>>y;
        long long ans=INF;
        for(auto [i,tx]:stLines[x]){
            for(auto [j,ty]:stLines[y]){
                if(dist[i][j]>=INF) continue;
                long long cur = w[x] + tx + dist[i][j] + ty + w[y];
                if(cur<ans) ans=cur;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
