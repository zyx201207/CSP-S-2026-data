#include<bits/stdc++.h>
using namespace std;
#define int long long
#define chkmin(x,y) (x)=min((x),(y))
const int N=505,M=500005,INF=0x3f3f3f3f3f3f3f3f;
vector<pair<int,int>> v[M];int c,n,m,d,q,w[M],dis[N][N];
signed main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q,memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++)  cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k,dis[i][i]=0;
        for(int j=1,a,t;j<=k;j++)  cin>>a>>t,v[a].emplace_back(i,t);
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)v[i].size();j++){
            int x=v[i][j].first,wx=v[i][j].second;
            for(int k=0;k<j;k++){
                int y=v[i][k].first,wy=v[i][k].second;
                chkmin(dis[x][y],wx+wy),chkmin(dis[y][x],wx+wy);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                chkmin(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1,x,y,res;i<=q;i++){
        cin>>x>>y,res=INF;
        for(auto it:v[x])  for(auto jt:v[y])
            chkmin(res,it.second+jt.second+dis[it.first][jt.first]);
        cout<<res+w[x]+w[y]<<"\n";
    }
}