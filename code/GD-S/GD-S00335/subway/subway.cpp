#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef pair<int,int> pii;
const int N=510,M=5e5+10,inf=1e18;
int c,n,m,d,q,dis[N],k[N],w[M];
vector<vector<int> >a,t,cot;
vector<int> vec[M];
vector<pii >g[N],G[N];
int e[N][N];
void dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii> >q;
    For(i,1,n+2) dis[i]=inf;
    dis[n+1]=0;
    q.push({0,n+1});
    while(!q.empty()){
        int u=q.top().second,W=q.top().first;
        q.pop();
        if(dis[u]!=W) continue;
        For(i,0,(int)(g[u].size()-1)){
            int v=g[u][i].first,w=g[u][i].second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
void add(int u,int v,int w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    a.resize(n+1),t.resize(n+1);
    cot.resize(m+1);
    For(i,1,m) cin>>w[i],cot[i].resize(n+1);
    For(i,1,n){
        cin>>k[i];
        a[i].resize(k[i]+1),t[i].resize(k[i]+1);
        For(j,1,k[i]) cin>>a[i][j]>>t[i][j],vec[a[i][j]].push_back(i),cot[a[i][j]][i]=t[i][j];
    }
    For(i,1,n){
        For(j,1,n){
            e[i][j]=inf;
        }
    }
    For(i,1,m){
        if(vec[i].empty()) continue;
        For(x,0,vec[i].size()-1){
            For(y,x+1,vec[i].size()-1){
                e[vec[i][x]][vec[i][y]]=min(e[vec[i][x]][vec[i][y]],cot[i][vec[i][x]]+cot[i][vec[i][y]]);
                e[vec[i][y]][vec[i][x]]=e[vec[i][x]][vec[i][y]];
            }
        }
    }
    For(i,1,n){
        For(j,i+1,n){
            if(e[i][j]!=inf){
                G[i].push_back({j,e[i][j]});
                G[j].push_back({i,e[i][j]});
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        For(i,1,n+2) g[i]=G[i];
        For(i,0,(int)(vec[x].size()-1)) add(n+1,vec[x][i],cot[x][vec[x][i]]);
        For(i,0,(int)(vec[y].size()-1)) add(n+2,vec[y][i],cot[y][vec[y][i]]);
        dijkstra();
        cout<<w[x]+w[y]+dis[n+2]<<'\n';
    }
    return 0;
}