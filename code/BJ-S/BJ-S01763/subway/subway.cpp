#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
const int maxn=505;
const int maxm=500005;
const ll inf=0x3f3f3f3f3f3f3f3f;
int cid,n,m,d,q,w[maxm];
ll dis[maxn][maxn];
vector<pair<int,int>> vc[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>cid>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int t;cin>>t;
        while(t--){
            int x,y;cin>>x>>y;
            vc[x].push_back(make_pair(i,y));
        }
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)dis[i][j]=inf;
    for(int i=1;i<=m;++i){
        for(int j1=0;j1<vc[i].size();++j1)for(int j2=j1+1;j2<vc[i].size();++j2){
            int x=vc[i][j1].first,y=vc[i][j2].first;
            dis[x][y]=dis[y][x]=min(dis[x][y],(ll)vc[i][j1].second+vc[i][j2].second);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)for(int u=1;u<=n;++u){
            dis[j][u]=min(dis[j][u],dis[j][i]+dis[i][u]);
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        ll ans=inf;
        for(int i=0;i<vc[x].size();++i)for(int j=0;j<vc[y].size();++j){
            ans=min(ans,vc[x][i].second+vc[y][j].second+dis[vc[x][i].first][vc[y][j].first]);
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}