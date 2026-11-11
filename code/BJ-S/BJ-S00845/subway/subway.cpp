#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10;
const int N=510;
const int Inf=0x3f3f3f3f3f3f3f3fll;
int w[M];
vector<pair<int,int> > l[N];//line->pos
vector<pair<int,int> > r[M];//pos->line
int dis[N][N];
void solve(int n){
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    return;
}
void addedge(int u,int v,int k){
    dis[u][v]=dis[v][u]=min(dis[u][v],k);
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    memset(dis,0x3f,sizeof(dis));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int p,t;
            cin>>p>>t;
            l[i].push_back({p,t});
            r[p].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<r[i].size();j++){
            for(int k=j+1;k<r[i].size();k++){
                addedge(r[i][j].first,r[i][k].first,r[i][j].second+r[i][k].second);
            }
        }
    }
    solve(n);
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=Inf;
        for(int i=0;i<r[x].size();i++){
            for(int j=0;j<r[y].size();j++){
                ans=min(ans,r[x][i].second+dis[r[x][i].first][r[y][j].first]+r[y][j].second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}

