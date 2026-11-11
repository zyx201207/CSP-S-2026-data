#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
typedef long long ll;
int c,n,m,d,q;
int w[M],k[N];
ll dis[N][N];
struct nodea{
    int id,t;
}a[N][M];
vector<nodea>v[M];
void myclear(ll x){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)dis[i][j]=x;
    }
}
void gmin(ll &a,ll b){
    a=min(a,b);
}
void init(){
    for(int i=1;i<=m;i++){
        for(auto na:v[i]){
            int u=na.id,ta=na.t;
            for(auto nb:v[i]){
                int v=nb.id,tb=nb.t;
                if(u==v)continue;
                gmin(dis[u][v],ta+tb);
                gmin(dis[v][u],ta+tb);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                gmin(dis[i][j],dis[i][k]+dis[k][j]);
                gmin(dis[j][i],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    myclear(1e18);
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int st,t;
            cin>>st>>t;
            a[i][j].id=st,a[i][j].t=t;
            v[st].push_back({i,t});
        }
    }
    init();
    while(q--){
        int st,ed;
        ll mn=1e18;
        cin>>st>>ed;
        for(auto na:v[st]){
            int u=na.id,ta=na.t;
            for(auto nb:v[ed]){
                int v=nb.id,tb=nb.t;
                gmin(mn,1ll*w[st]+w[ed]+ta+tb+dis[u][v]);
            }
        }
        cout<<mn<<"\n";
    }
    return 0;
}
