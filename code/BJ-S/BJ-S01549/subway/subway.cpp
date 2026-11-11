#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
using namespace std;

const int N=505,M=5e5+5;
ll g[N][N];
vector<pii> ps[M]; // id   time
int c,n,m,d,q;
ll w[M];

void Floyd(){
    for(int i=1;i<=n;i++){
        g[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k,a,t;cin>>k;
        while(k--){
            cin>>a>>t;
            ps[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int p=0;p<ps[i].size();p++){
            for(int q=p+1;q<ps[i].size();q++){
                int u=ps[i][p].first,v=ps[i][q].first;
                g[u][v]=min(g[u][v],ps[i][p].second+ps[i][q].second);
                g[v][u]=min(g[v][u],ps[i][p].second+ps[i][q].second);
            }
        }
    }
    Floyd();
    while(q--){
        int x,y;cin>>x>>y;
        ll ans=9e18;
        for(int p=0;p<ps[x].size();p++){
            for(int q=0;q<ps[y].size();q++){
                int u=ps[x][p].first,v=ps[y][q].first;
                ans=min(ans,w[x]+w[y]+ps[x][p].second+ps[y][q].second+g[u][v]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}