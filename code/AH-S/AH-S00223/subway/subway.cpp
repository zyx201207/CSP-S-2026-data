#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=505,M=5e5+5;
int c;
int n,m,d,q; //分别表示地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。
ll w[M]; //每个地铁站的地铁口走到站厅需要的时间
struct node{
    int state;
    ll tim;
};
int k[N];
ll tim[N][M];
ll e[N][N],dis[N][N];
vector<int> past[M];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int s,t; cin>>s>>t;
            tim[i][s]=t;
            past[s].push_back(i);
        }
    }
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=n;i++) e[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int u:past[i])
            for(int v:past[i])
                e[u][v]=e[v][u]=min(e[u][v],tim[u][i]+tim[v][i]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=dis[j][i]=e[i][j];
    for(int p=1;p<=n;p++)
        for(int u=1;u<=n;u++)
            for(int v=u+1;v<=n;v++)
                dis[u][v]=dis[v][u]=min(dis[u][v],dis[u][p]+dis[p][v]);

    while(q--){
        int s,t; cin>>s>>t;
        ll ans=1e18;
        for(int u:past[s])
            for(int v:past[t]){
                ans=min(ans,w[s]+tim[u][s]+dis[u][v]+tim[v][t]+w[t]);
                //if(q==1999) cerr<<w[s]<<' '<<tim[u][s]<<' '<<dis[u][v]<<' '<<tim[v][t]<<' '<<w[t]<<'\n';
            }
        cout<<ans<<'\n';
    }

    return 0;
}
