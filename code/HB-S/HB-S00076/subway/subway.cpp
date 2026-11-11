#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int> 
const int N=1005;

int c,n,m,d,q;
int w[N],k[N],a[N][N],t[N][N];
int dis[N];
vector<pair<int,int>> g[N];

int dij(int x,int y){
    for(int i=1;i<=m;i++) dis[i]=1e18;
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    pq.push({w[x],x});
    dis[x]=w[x];
    while(!pq.empty()){
        PII now=pq.top();
        pq.pop();

        int u=now.second;
        if(u==y){
            return dis[u]+w[y];
        }

        for(auto q:g[u]){
            int p=q.first;
            int myt=q.second;
            for(int i=1;i<=k[p];i++){
                if(a[p][i]==u) continue;
                int cost=t[p][i]+myt;
                if(dis[u]+cost<dis[a[p][i]]){
                    dis[a[p][i]]=dis[u]+cost;
                    pq.push({dis[a[p][i]],a[p][i]});
                }
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

        for(int i=1;i<=m;i++) cin>>w[i];
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[i][j]>>t[i][j];
                g[a[i][j]].push_back({i,t[i][j]});
            }
        }

        while(q--){
            int x,y;cin>>x>>y;
            cout<<dij(x,y)<<endl;
        }
}