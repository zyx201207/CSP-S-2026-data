//15:15
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5+5;
const int N = 505;
int c,n,m,d,q,w[M];
vector<pair<int,int>>ve[M];
int e[N][N],dis[N][N];
void Main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,x,t;j<=k;j++){
            cin>>x>>t;
            ve[x].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int p=0;p<(int)ve[i].size();p++){
            for(int o=p+1;o<(int)ve[i].size();o++){
                int u=ve[i][p].first,v=ve[i][o].first;
                dis[u][v]=dis[v][u]=min(dis[u][v],ve[i][p].second+ve[i][o].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for(int i=1,u,v;i<=q;i++){
        cin>>u>>v;
        int ans=dis[0][0];
        for(int p=0;p<(int)ve[u].size();p++){
            for(int o=0;o<(int)ve[v].size();o++){
                int x=ve[u][p].first,y=ve[v][o].first;
                ans=min(ans,ve[u][p].second+ve[v][o].second+dis[x][y]+w[u]+w[v]);
            }
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    while(T--)Main();
}