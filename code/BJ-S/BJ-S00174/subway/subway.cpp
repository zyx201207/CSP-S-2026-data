#include <bits/stdc++.h>
#define N 502
#define M 2000002
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3fll;
struct node{ll u,t;};
ll c,n,m,d,q,w[M],dis[N][N],k[N];
vector<ll> a[N],t[N];
vector<node> l[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)  cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];a[i].resize(k[i]+1),t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            l[a[i][j]].push_back({i,t[i][j]});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)  dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<l[i].size();j++){
            for(int k=0;k<j;k++){
                ll u=l[i][j].u,v=l[i][k].u,t=l[i][j].t+l[i][k].t;
                dis[u][v]=min(dis[u][v],t),dis[v][u]=min(dis[v][u],t);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;cin>>u>>v;
        ll res=inf;
        for(auto [i,ti]:l[u]){
            for(auto [j,tj]:l[v]){
                res=min(res,w[u]+w[v]+ti+tj+dis[i][j]);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}