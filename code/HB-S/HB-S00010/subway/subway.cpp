#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define PII pair<int,ll>
#define A first
#define B second
const int N=505,M=5e5+5;
using namespace std;
int c,n,m,d,q;
ll w[M],dis[N][N];
vector<PII> e[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int u,tu;cin>>u>>tu;
            e[u].push_back(PII{i,tu});
        }
    }memset(dis,0x3f,sizeof(dis));
    for(int k=1;k<=m;k++){
        int len=e[k].size();
        for(int i=0;i<len;i++)for(int j=0;j<len;j++){
            if(i==j)continue;int x=e[k][i].A,y=e[k][j].A;
            dis[y][x]=dis[x][y]=min(dis[x][y],e[k][i].B+e[k][j].B);
        }
    }for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//        cout<<"\n";
//    }
    while(q--){
        int x,y;cin>>x>>y;ll ans=2e18;
        int lenx=e[x].size(),leny=e[y].size();
        for(int i=0;i<lenx;i++)for(int j=0;j<leny;j++)
            ans=min(ans,dis[e[x][i].A][e[y][j].A]+e[x][i].B+e[y][j].B);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
